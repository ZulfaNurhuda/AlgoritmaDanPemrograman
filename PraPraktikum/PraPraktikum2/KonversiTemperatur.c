#include <stdio.h>
#include <math.h>

void ConvertTemperatures(int N, double suhu[], char suhu_awal[], char suhu_akhir[], double hasil[])
{
    for (int i = 0; i < N; i++)
    {
        if (suhu_awal[i] == 'C' && suhu_akhir[i] == 'F')
        {
            hasil[i] = suhu[i] * 9.0 / 5.0 + 32;
        }
        else if (suhu_awal[i] == 'C' && suhu_akhir[i] == 'K')
        {
            hasil[i] = suhu[i] + 273.15;
        }
        else if (suhu_awal[i] == 'F' && suhu_akhir[i] == 'C')
        {
            hasil[i] = (suhu[i] - 32) * 5.0 / 9.0;
        }
        else if (suhu_awal[i] == 'F' && suhu_akhir[i] == 'K')
        {
            hasil[i] = (suhu[i] - 32) * 5.0 / 9.0 + 273.15;
        }
        else if (suhu_awal[i] == 'K' && suhu_akhir[i] == 'C')
        {
            hasil[i] = suhu[i] - 273.15;
        }
        else if (suhu_awal[i] == 'K' && suhu_akhir[i] == 'F')
        {
            hasil[i] = (suhu[i] - 273.15) * 9.0 / 5.0 + 32;
        }
        else
        {
            hasil[i] = suhu[i];
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    double suhu[N], hasil[N];
    char suhu_awal[N], suhu_akhir[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%lf %c %c", &suhu[i], &suhu_awal[i], &suhu_akhir[i]);
    }

    ConvertTemperatures(N, suhu, suhu_awal, suhu_akhir, hasil);

    for (int i = 0; i < N; i++)
    {
        printf("%.2f\n", floor(hasil[i]));
    }

    return 0;
}