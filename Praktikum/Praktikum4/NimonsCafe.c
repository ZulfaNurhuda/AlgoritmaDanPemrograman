#include "NimonsCafe.h"

PesananMinuman BuatPesanan(char *nama, char ukuran, TipeGula tGula, TipeEs tEs)
{
    PesananMinuman p;

    setNamaMinuman(&p, nama);
    setUkuran(&p, ukuran);
    setTipeGula(&p, tGula);
    setTipeEs(&p, tEs);

    return p;
}

char *getNamaMinuman(PesananMinuman *p)
{
    return p->namaMinuman;
}

void setNamaMinuman(PesananMinuman *p, char *nama)
{
    strcpy(p->namaMinuman, nama);
}

char getUkuran(PesananMinuman p)
{
    return p.ukuran;
}

void setUkuran(PesananMinuman *p, char ukuran)
{
    p->ukuran = ukuran;
}

TipeGula getTipeGula(PesananMinuman p)
{
    return p.tipeGula;
}

void setTipeGula(PesananMinuman *p, TipeGula tGula)
{
    p->tipeGula = tGula;
}

TipeEs getTipeEs(PesananMinuman p)
{
    return p.tipeEs;
}

void setTipeEs(PesananMinuman *p, TipeEs tEs)
{
    p->tipeEs = tEs;
}

void TulisPesanan(PesananMinuman p)
{
    char tipeGula[15];
    char tipeEs[15];

    switch (p.tipeGula)
    {
    case LESS_SUGAR:
        strcpy(tipeGula, "less sugar");
        break;
    case NORMAL_SUGAR:
        strcpy(tipeGula, "normal sugar");
        break;
    case EXTRA_SUGAR:
        strcpy(tipeGula, "extra sugar");
        break;
    }

    switch (p.tipeEs)
    {
    case LESS_ICE:
        strcpy(tipeEs, "less ice");
        break;
    case NORMAL_ICE:
        strcpy(tipeEs, "normal ice");
        break;
    case NO_ICE:
        strcpy(tipeEs, "no ice");
        break;
    }

    printf("%s - %c - %s, %s\n", p.namaMinuman, p.ukuran, tipeGula, tipeEs);
}

int TotalKalori(PesananMinuman p)
{
    int kalori = 0;

    switch (p.ukuran)
    {
    case 'S':
        kalori += 100;
        break;
    case 'M':
        kalori += 150;
        break;
    case 'L':
        kalori += 200;
        break;
    }

    switch (p.tipeGula)
    {
    case LESS_SUGAR:
        kalori += 10;
        break;
    case NORMAL_SUGAR:
        kalori += 20;
        break;
    case EXTRA_SUGAR:
        kalori += 40;
        break;
    }

    return kalori;
}

int VolumeBersih(PesananMinuman p)
{
    int volume = 0;

    switch (p.ukuran)
    {
    case 'S':
        volume = 240;
        break;
    case 'M':
        volume = 360;
        break;
    case 'L':
        volume = 480;
        break;
    }

    switch (p.tipeEs)
    {
    case LESS_ICE:
        volume -= (volume * 10) / 100;
        break;
    case NORMAL_ICE:
        volume -= (volume * 25) / 100;
        break;
    }

    return volume;
}