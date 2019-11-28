#include "a.h"
#if 0
A::A()
{

}
#endif

template <typename Type>
void A<Type>::func(Type & num) {
    cout << num << endl;
}
