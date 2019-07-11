#include <memory>
#include <vector>

enum class KernelType
{
    GaussianKernelT = 0
};

template <typename Type>
class Kernel;
class KernelArgs;

class KernelFactory
{
public:
    template <typename Type>
    static std::shared_ptr<Kernel<Type>> create_kernel(const KernelType &,
                                                       const KernelArgs &);
};

template <typename Type>
class Kernel
{
protected:
    size_t height;
    size_t width;
    std::vector<Type> data;

public:
    virtual const std::vector<Type> &get_data();
    virtual ~Kernel() = default;
};

class GaussianKernel;
