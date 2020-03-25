#include <pybind11/pybind11.h>

namespace py = pybind11;

int add(int i, int j) {
    return i + j;
}

// PYBIND11_EXPORT int add(int,int);

PYBIND11_MODULE (example, m) {

    py::options options;
    options.disable_function_signatures();

    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("add", &add);


#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif

}
