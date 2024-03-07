/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(add_tag.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(ed6e15606d22607e8ecd66219f04805f)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/add_tag_module/add_tag.h>
// pydoc.h is automatically generated in the build directory
#include <add_tag_pydoc.h>

void bind_add_tag(py::module& m)
{
    using add_tag    = gr::add_tag_module::add_tag;
    py::class_<add_tag, gr::sync_block, gr::block, gr::basic_block,
        std::shared_ptr<add_tag>>(m, "add_tag", D(add_tag))
        .def(py::init(&add_tag::make),
            py::arg("burst"),
            D(add_tag,make))
        .def("set_burst",
             &add_tag::set_burst,
             py::arg("burst"),
             D(add_tag, set_burst))
        .def("burst", &add_tag::burst, D(add_tag, burst))
        ;
}