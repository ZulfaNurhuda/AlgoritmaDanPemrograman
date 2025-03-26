int f (void) {
    int s = 1;
    int t = 1;
    int *ps = &s;
    int **pps = &ps; // atau: int **pps; pps = &ps;
    int *pt = &t;

    **pps = 2; 
    pt = ps;
    *pt = 3;
    t = s;
}
