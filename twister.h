#ifndef PYTHON_EXTENSION_TWISTER_H
#define PYTHON_EXTENSION_TWISTER_H

void init_genrand(unsigned long s);
void init_by_array(const unsigned long init_key[], int key_length);
unsigned long genrand_int32(void);
long genrand_int31(void);
double genrand_real1(void);
double genrand_real2(void);
double genrand_real3(void);
double genrand_res53(void);

#endif //PYTHON_EXTENSION_TWISTER_H