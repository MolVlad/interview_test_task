#include "mex.h"
// #include "class_handle.hpp"
#include "C++/src/ML.hpp"
#include <string>


static ML* obj = nullptr;
static int8_t bit_num;

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    
// if (nrhs != 1) {
//         mexErrMsgTxt("One input required.");
//     }
// 
//     // Проверяем тип входного аргумента
//     // if (!mxIsComplex(prhs[0])) {
//     //     mexErrMsgTxt("Input must be a complex array.");
//     // }
// 
//     // Получаем указатель на данные и размер массива
//     std::complex<float>* data = (std::complex<float>*)mxGetData(prhs[0]);
//     mwSize size = mxGetNumberOfElements(prhs[0]);
// 
//     // Выводим элементы массива
//     std::cout << "Array elements:" << std::endl;
//     for (mwSize i = 0; i < size; ++i) {
//         std::cout << data[i] << " ";
//     }
//     std::cout << std::endl;

    if (!mxIsChar(prhs[0])) {
        mexErrMsgTxt("first input must be a char array");
    }
    char* command = mxArrayToString(prhs[0]);

    if (strcmp(command, "new") == 0) {
        if (obj != nullptr) {
            delete obj;
        }
        bit_num = mxGetScalar(prhs[1]);
        int8_t CIR_len = mxGetScalar(prhs[2]);
        obj = new ML(bit_num, CIR_len);
    }else if (strcmp(command, "run") == 0) {
        if (obj != nullptr) {
            std::complex<float>* sig = (std::complex<float>*)mxGetData(prhs[1]);
            // for (int i = 0; i < 3; i++)
            // cout<< sig[i] << " "; 
            // cout<<endl;
            std::complex<float>* CIR = (std::complex<float>*)mxGetData(prhs[2]);
            // mwSize size = mxGetNumberOfElements(prhs[0]);
            std::int8_t equilised_bits[bit_num];
            obj->run(sig, CIR, equilised_bits);
            plhs[0] = mxCreateNumericMatrix(1, bit_num, mxINT8_CLASS, mxREAL);
            std::memcpy(mxGetData(plhs[0]), equilised_bits, bit_num * sizeof(int8_t));
        } else {
            mexErrMsgTxt("Object not created.");
        }
    } else {
        mexErrMsgTxt("Unknown command.");
    }

    mxFree(command);
}
