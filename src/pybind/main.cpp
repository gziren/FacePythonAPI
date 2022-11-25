//
// Created by aichao on 2022/11/23.
//

#include "main.h"


void PyArrayToSeetaImageData(py::array_t<unsigned char> pyarray, SeetaImageData *data) {
    if (pyarray.ndim() != 3) {
        FRERROR << "input image dims must be 3 " << std::endl;
    } else {
        data->height = (int) pyarray.shape()[0];
        data->width = (int) pyarray.shape()[1];
        data->channels = (int) pyarray.shape()[2];
        data->data = pyarray.mutable_data();
    }
}

py::array_t<unsigned char> SeetaImageDataToPyArray(const SeetaImageData &data) {

    std::vector<int> shape = {data.height, data.width, data.channels};
    int size = std::accumulate(shape.begin(), shape.end(), 1, std::multiplies<int>());
    auto out = pybind11::array_t<unsigned char>(shape);
    memcpy(out.mutable_data(), data.data, size);
    return out;
}


PYBIND11_MODULE(PYFaceAPI, m) {
    m.doc() = "face api collection";
    BindStruct(m);
    BindFaceAPI(m);
}