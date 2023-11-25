#ifndef MATH_FUNCTIONS_HPP
#define MATH_FUNCTIONS_HPP

#ifdef __cplusplus
extern "C"
{
    #endif
    #define PCONS 3
    #define ECONS 1

    // Function declarations
    int alpha(int num);
    int beta(int num);
    //int inv_alpha(int num);
    //int inv_beta(int num);
    int lcf(int n, int k);
    int gcf(int n, int k);
    
    #ifdef __cplusplus
}
#endif

#endif
