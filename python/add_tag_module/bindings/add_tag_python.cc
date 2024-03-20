#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/add_tag_module/add_tag.h>
// pydoc.h is automatically generated in the build directory
#include <add_tag_pydoc.h>

void bind_add_tag(py::module& m)
{
    using add_tag = gr::add_tag_module::add_tag;
    py::class_<add_tag,
               gr::sync_block,
               gr::block,
               gr::basic_block,
               std::shared_ptr<add_tag>>(m, "add_tag", D(add_tag))
        .def(py::init(&add_tag::make),
             py::arg("itemsize"),
             py::arg("num_ports"),
             py::arg("burst"),
             py::arg("number_of_samples_to_record"),
             py::arg("filename"),
             D(add_tag, make))
        .def("set_burst", &add_tag::set_burst, py::arg("burst"), D(add_tag, set_burst))
        .def("burst", &add_tag::burst, D(add_tag, burst))
        .def("set_filename",
             &add_tag::set_filename,
             py::arg("filename"),
             D(add_tag, set_filename))
        .def("filename", &add_tag::filename, D(add_tag, filename));
}