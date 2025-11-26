#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Clase para demostrar class, public, private, protected
class BaseClass {
private:
    int privateVar;
protected:
    int protectedVar;
public:
    virtual void virtualFunc() {}
    static int staticVar;
    friend void friendFunc();
    explicit BaseClass(int val) : privateVar(val) {}
    virtual ~BaseClass() {}
};

// struct y typedef
struct MyStruct {
    int x;
    double y;
};

typedef int Integer;

// union
union MyUnion {
    int i;
    float f;
    char c;
};

// enum y enum class
enum Color { RED, GREEN, BLUE };
enum class Status { ACTIVE, INACTIVE };

// template
template <typename T, class U>
T templateFunc(T a, U b) {
    return static_cast<T>(a + b);
}

// namespace
namespace MyNamespace {
    void func() {}
}

// Función con todas las palabras clave de control de flujo
void controlFlow() {
    // if, else
    if (true) {
        cout << "if" << endl;
    } else if (false) {
        cout << "else if" << endl;
    } else {
        cout << "else" << endl;
    }

    // switch, case, default, break
    int x = 1;
    switch (x) {
        case 1:
            cout << "case 1" << endl;
            break;
        case 2:
            cout << "case 2" << endl;
            break;
        default:
            cout << "default" << endl;
            break;
    }

    // while
    int i = 0;
    while (i < 5) {
        i++;
        if (i == 3) continue;
        if (i == 4) break;
    }

    // do-while
    do {
        cout << "do-while" << endl;
    } while (false);

    // for
    for (int j = 0; j < 10; j++) {
        if (j == 5) break;
        if (j == 3) continue;
    }

    // Range-based for
    vector<int> vec = {1, 2, 3};
    for (auto& elem : vec) {
        cout << elem << endl;
    }

    // goto
    goto label;
    label:
    cout << "goto label" << endl;
}

// Función con try, catch, throw
void exceptionHandling() {
    try {
        throw runtime_error("Error");
    } catch (const exception& e) {
        cout << e.what() << endl;
    } catch (...) {
        cout << "catch all" << endl;
    }
}

// Clase derivada para demostrar inheritance
class DerivedClass : public BaseClass {
public:
    DerivedClass() : BaseClass(0) {}
    
    void virtualFunc() override final {
        // override y final (C++11)
    }
    
    void constFunc() const {
        // const
    }
    
    void volatileFunc() volatile {
        // volatile
    }
};

// Operadores y conversiones
void operators() {
    int a = 10;
    int* ptr = &a;              // Operador &
    int value = *ptr;           // Operador *
    (void)value;                // Suprimir warning de variable no usada
    
    // sizeof
    size_t size = sizeof(int);
    
    // new y delete
    int* dynamic = new int(5);
    delete dynamic;
    
    int* arr = new int[10];
    delete[] arr;
    
    // const_cast, static_cast, dynamic_cast, reinterpret_cast
    const int constVal = 10;
    int* modifiable = const_cast<int*>(&constVal);
    
    double d = static_cast<double>(a);
    
    BaseClass* base = new DerivedClass();
    DerivedClass* derived = dynamic_cast<DerivedClass*>(base);
    
    long addr = reinterpret_cast<long>(ptr);
    
    delete base;
    
    // typeid
    const type_info& info = typeid(a);
}

// Especificadores de almacenamiento
extern int externVar;
static int staticVar = 0;
// register int registerVar = 0;  // deprecated y no permitido en ámbito global
thread_local int threadVar = 0;

// mutable
class MutableExample {
    mutable int counter;
public:
    void increment() const {
        counter++;  // permitido por mutable
    }
};

// inline
inline int inlineFunc(int x) {
    return x * 2;
}

// constexpr (C++11)
constexpr int constexprFunc(int x) {
    return x * x;
}

// noexcept (C++11)
void noexceptFunc() noexcept {
    // no lanza excepciones
}

// nullptr (C++11)
void nullptrExample() {
    int* ptr = nullptr;
}

// alignas y alignof (C++11)
struct alignas(16) AlignedStruct {
    int x;
};

// static_assert (C++11)
static_assert(sizeof(int) == 4, "int debe ser de 4 bytes");

// decltype (C++11)
void decltypeExample() {
    int x = 5;
    decltype(x) y = 10;
}

// Función main
int main() {
    // auto (C++11)
    auto autoVar = 42;
    
    // const y constexpr
    const int CONSTANT = 100;
    constexpr int COMPILE_TIME = 200;
    
    // bool, true, false
    bool boolean = true;
    boolean = false;
    
    // Tipos básicos
    char character = 'a';
    wchar_t wideChar = L'A';
    char16_t char16 = u'B';
    char32_t char32 = U'C';
    
    short shortInt = 1;
    int integer = 2;
    long longInt = 3L;
    long long longLongInt = 4LL;
    
    signed int signedInt = -5;
    unsigned int unsignedInt = 6u;
    
    float floatNum = 3.14f;
    double doubleNum = 3.14159;
    long double longDouble = 3.14159265L;
    
    void* voidPtr = nullptr;
    
    // this
    class ThisExample {
    public:
        int value;
        ThisExample* getThis() {
            return this;
        }
    };
    
    // operator overloading
    class OperatorExample {
    public:
        int operator+(const OperatorExample& other) {
            return 0;
        }
    };
    
    // asm (inline assembly)
    // asm("nop");
    
    controlFlow();
    exceptionHandling();
    operators();
    
    return 0;
}