
volatile int varInt = 1;
volatile long varLong = 0;
volatile char varChar = '1';
volatile float varFloat = 0.0f;

int main() {
    varInt = 10;
    varChar = '1';
    varFloat = 2.f;
    varLong = 100000000;
    return 0;
}
