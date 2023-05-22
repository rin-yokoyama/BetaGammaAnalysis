#include "EuricaBetaTSScanner.h"

const std::string eurica::BetaTSScanner::kMsgPrefix("[BetaTSScanner]:");

void eurica::BetaTSScanner::SetReader()
{
    TSScannerBase<eurica::ImplantData>::SetReader();
    std::string br_name = yaml_reader_->GetString("BranchName");
    tree_data_ = new TTreeReaderValue<eurica::ImplantData>(*tree_reader_, br_name.c_str());
    std::cout << kMsgPrefix << "TreeReaderValue: " << br_name << " created." << std::endl;
    return;
}

Bool_t eurica::BetaTSScanner::IsInGate()
{
    const auto data = tree_data_->Get();
    // skip event if bigrips data is NOT empty
    if (!data->output_vec_.empty())
        return false;
    const auto &x_vec = data->input_.input_.x_;
    if (!std::any_of(x_vec.begin(), x_vec.end(), [](const eurica::WasabiHitData x)
                     { return x.layer_; }))
        return false;
    const auto &y_vec = data->input_.input_.y_;
    if (!std::any_of(y_vec.begin(), y_vec.end(), [](const eurica::WasabiHitData x)
                     { return x.layer_; }))
        return false;
    return true;
}
