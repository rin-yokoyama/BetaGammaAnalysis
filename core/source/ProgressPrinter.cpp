#include "ProgressPrinter.h"

const std::string ProgressPrinter::kMsgPrefix("[ProgressPrinter]: ");

void ProgressPrinter::PrintProgress(const unsigned long long &prog)
{
	if (!(prog % print_frequency_))
	{
		tm *remain_time = remain(prog);
		std::cout << kMsgPrefix << prog << "/" << total << " ";
		std::cout << 100. * (double)prog / (double)total << "\% scanned. Remaining " << remain_time->tm_hour << "h ";
		std::cout << remain_time->tm_min << "m " << remain_time->tm_sec << "s" << std::endl;
	}
}