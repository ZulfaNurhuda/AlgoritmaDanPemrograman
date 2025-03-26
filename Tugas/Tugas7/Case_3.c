int main()
{
    char blocks[3] = {'I', 'T', 'B'}; // misal, alamat array blocks adalah 4434
    char *ptr = &blocks[0];
    char temp;

    temp = blocks[0];
    temp = *(blocks + 2);
    temp = *(ptr + 1);
    temp = *ptr;

    ptr = blocks + 1;
    temp = *ptr;
    temp = *(ptr + 1);

    ptr = blocks;
    temp = *++ptr;
    temp = ++*ptr;
    temp = *ptr++;
    temp = *ptr;

    return 0;
}
