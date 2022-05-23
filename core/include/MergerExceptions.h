#include <stdexcept>

class MergerInvalidInitializationException : public std::runtime_error
{
public:
    MergerInvalidInitializationException(const char *_Message)
        : runtime_error(_Message)
    {
    }
};