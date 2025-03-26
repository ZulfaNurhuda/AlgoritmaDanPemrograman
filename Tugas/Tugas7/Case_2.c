int *value(void)
{
    int i = 3;
    return &i;
}
void callme(void)
{
    int x = 35;
}

int main(void)
{
    int *ip;
    ip = value();
    printf("*ip == %d\n", *ip);
    callme();
    printf("*ip == %d\n", *ip);
}