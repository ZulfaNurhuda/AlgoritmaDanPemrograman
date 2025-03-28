#include "NimonsAttack.h"

float hitungJarakKePulau(Kapal kapal, Koordinat pulau)
{
    return sqrt(pow(kapal.posisi.x - pulau.x, 2) + pow(kapal.posisi.y - pulau.y, 2));
}

float hitungJarakKeKapal(Kapal kapal1, Kapal kapal2)
{
    return sqrt(pow(kapal1.posisi.x - kapal2.posisi.x, 2) + pow(kapal1.posisi.y - kapal2.posisi.y, 2));
}


boolean isKapalValid(Kapal kapal, Koordinat pulau, Kapal *listKapal, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (kapal.posisi.x == listKapal[i].posisi.x && kapal.posisi.y == listKapal[i].posisi.y)
        {
            printf("%s nabrak kapal lain dong!\n", kapal.kode);
            return FALSE;
        }
        if (!strcmp(kapal.kode, listKapal[i].kode))
        {
            printf("%s kok ada dua!\n", kapal.kode);
            return FALSE;
        }
    }
    if (kapal.posisi.x == pulau.x && kapal.posisi.y == pulau.y)
    {
        printf("%s nabrak pulau dong!\n", kapal.kode);
        return FALSE;
    }
    return TRUE;
}

void urutkanKapalTerdekat(Kapal *listKapal, Koordinat pulau, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (hitungJarakKePulau(listKapal[i], pulau) > hitungJarakKePulau(listKapal[j], pulau))
            {
                Kapal temp = listKapal[i];
                listKapal[i] = listKapal[j];
                listKapal[j] = temp;
            }
        }
    }
}

void cariKapalTerdekat()
{
    int N, R;
    scanf("%d %d", &N, &R);

    Koordinat pulau;
    scanf("%d %d", &pulau.x, &pulau.y);

    Kapal listKapal[N];
    int i = 0;

    while (i < N)
    {
        Kapal inspeksi;
        scanf("%d %d %s", &inspeksi.posisi.x, &inspeksi.posisi.y, inspeksi.kode);

        if (isKapalValid(inspeksi, pulau, listKapal, i))
        {
            listKapal[i] = inspeksi;
            i++;
        }
    }

    urutkanKapalTerdekat(listKapal, pulau, N);

    for (int i = 0; i < N; i++)
    {
        Kapal target = listKapal[i];
        if (hitungJarakKePulau(target, pulau) <= R)
        {
            printf("%d - %s (%d,%d)\n", i + 1, target.kode, target.posisi.x, target.posisi.y);
        }
        else
        {
            printf("Perdamaian di pulau Mackenbruh telah usai :(\n");
            break;
        }
    }
}