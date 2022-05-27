#include "TTreeEventBuilder.h"

void TTreeEventBuilder::Configure(const std::string &node_name)
{
    yaml_reader_ = new YamlReader(node_name);
    time_window_ = yaml_reader_->GetDouble("TimeWindow", false, 1000);
}

void TTreeEventBuilder::Loop()
{
    event_loaders_.erase(std::remove_if(event_loaders_.begin(), event_loaders_.end(), [](TTreeEventLoaderBase *a)
                                        { return a->IsEmpty(); }),
                         event_loaders_.end());
    /// Find the smallest and largest timestamp values.
    auto min_itr = std::min_element(
        event_loaders_.begin(),
        event_loaders_.end(),
        [](TTreeEventLoaderBase *a, TTreeEventLoaderBase *b)
        { return a->GetFirstTS() < b->GetFirstTS(); });
    auto max_itr = std::max_element(
        event_loaders_.begin(),
        event_loaders_.end(),
        [](TTreeEventLoaderBase *a, TTreeEventLoaderBase *b)
        { return a->GetLastTS() < b->GetLastTS(); });
    double min_ts = (*min_itr)->GetFirstTS();
    double max_ts = (*max_itr)->GetLastTS();
    Restart();
    prog_ = new ProgressPrinter(min_ts, max_ts, print_freq_);
    // prog_ = new ProgressPrinter(0, 1, print_freq_);
    for (auto &loader : event_loaders_)
    {
        while (!loader->GetNext() && !loader->GetEoF())
        {
        }
    }
}

bool TTreeEventBuilder::CheckEoF()
{
    bool eof = true;
    for (const auto &loader : event_loaders_)
    {
        eof = eof && loader->GetEoF();
    }
    return eof;
}

void TTreeEventBuilder::Restart()
{
    for (auto &loader : event_loaders_)
    {
        loader->Restart();
    }
}

void TTreeEventBuilder::Sort()
{
    std::sort(
        event_loaders_.begin(),
        event_loaders_.end(),
        [](const decltype(event_loaders_)::value_type &a, const decltype(event_loaders_)::value_type &b)
        {
            return a->GetTS() < b->GetTS();
        });
}