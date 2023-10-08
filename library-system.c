//
// Created by User on 08/10/2023.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

enum Penerbit {
    Alexindo,
    Gramedia,
    Elexmedia,
    Pustaka
};

void daftarPenerbit(){
    printf("Daftar Penerbit");
    printf("\n1.Alexindo");
    printf("\n2.Gramedia");
    printf("\n3.Elexmedia");
    printf("\n4.Pustaka");
    printf("\nSilahkan Pilih Penerbit :");
};

char* penerbitString(enum Penerbit penerbit){
    switch (penerbit) {
        case Alexindo:    return "Alexindo";
        case Gramedia:    return "Gramedia";
        case Elexmedia:   return "Elexmedia";
        case Pustaka: return "Pustaka";
        default: return "Invalid Category";
    }
}

enum Kategori {
    Novel,
    Sejarah,
    Teks,
    Fiksi,
    Komik
};

void daftarKategori(){
    printf("Daftar Kategori");
    printf("\n1.Novel");
    printf("\n2.Sejarah");
    printf("\n3.Teks");
    printf("\n4.Fiksi");
    printf("\n5.Komik");
    printf("\nSilahkan Pilih Kategori :");
}

char* kategoriString(enum Kategori kategori){
    switch (kategori) {
        case Novel:    return "Novel";
        case Sejarah:    return "Sejarah";
        case Teks:   return "Teks";
        case Fiksi: return "Fiksi";
        case Komik:  return "Komik";
        default: return "Invalid Category";
    }
}

typedef struct {
    char judul[100];
    char pengarang[100];
    int tahunTerbit;
    enum Kategori kategori;
    enum Penerbit penerbit;
    int jumlahBuku;
} Buku;

int findIndexBuku(Buku* daftarBuku,int jumlahBuku,char* judulBuku){
    for (int i = 0; i < jumlahBuku; ++i) {
        if (strcmp(judulBuku,daftarBuku[i].judul) == 0){
            return i;
        }
    }
    return -1;
}

typedef struct {
    char judulBuku[100];
    char namaPeminjam[100];
} Peminjam;

int main(){
    int pilihan;
    Buku daftarBuku[100];
    Peminjam daftarPeminjam[100];
    int indexDaftarBuku = 0;
    int indexDaftarPeminjam = 0;
    bool isRun = true;
    while (isRun){
        Buku buku;
        Peminjam peminjam;
        int indexBukuDibuang;
        int indexBukuDipinjam;
        int indexPengembalian;
        int indexBukuDikembalikan;
        printf("PUSTAKA SEJAHTERA - Simplified");
        printf("\n1. Tambah Buku");
        printf("\n2. Lihat Daftar Buku");
        printf("\n3. Buang Buku");
        printf("\n4. Peminjaman Buku");
        printf("\n5 Lihat Daftar Peminjam Buku");
        printf("\n6. Pengembalian Buku");
        printf("\n7. Exit Program");
        printf("\nSilahkan Masukan Pilihan Anda :");
        scanf("%d", &pilihan);
        switch (pilihan) {
            case 1:
                fflush(stdin);
                printf("Masukan Judul Buku :");
                scanf("%[^\n]",buku.judul);
                fflush(stdin);
                printf("Masukan Pengarang Buku :");
                scanf("%[^\n]",buku.pengarang);
                fflush(stdin);
                printf("Masukan Tahun Terbit Buku :");
                scanf("%d", &buku.tahunTerbit);
                daftarKategori();
                scanf("%d", &buku.kategori);
                buku.kategori -= 1;
                daftarPenerbit();
                scanf("%d", &buku.penerbit);
                buku.penerbit -= 1;
                printf("Masukan Jumlah Buku :");
                scanf("%d", &buku.jumlahBuku);
                daftarBuku[indexDaftarBuku] = buku;
                indexDaftarBuku++;
                break;
            case 2:
                for (int i = 0; i < indexDaftarBuku; ++i) {
                    printf("%i. %s [%s] [%s] [%s] [%i] (%i buku)",i+1,daftarBuku[i].judul,daftarBuku[i].pengarang,
                           penerbitString(daftarBuku[i].penerbit), kategoriString(daftarBuku[i].kategori),daftarBuku[i].tahunTerbit,daftarBuku[i].jumlahBuku);
                    if (i != indexDaftarBuku){
                        printf("\n");
                    }
                }
                break;
            case 3:
                printf("Masukan Nomor Buku Untuk Dibuang :");
                scanf("%d", &indexBukuDibuang);
                indexBukuDibuang -= 1;
                for (int i = indexBukuDibuang; i < indexDaftarBuku+1; ++i) {
                    if(i + 1 != indexDaftarBuku+1){
                        daftarBuku[i] = daftarBuku[i+1];
                    }
                }
                indexDaftarBuku -= 1;
                break;
            case 4:
                printf("Masukan Nomor Buku Untuk Dipinjam :");
                scanf("%d", &indexBukuDipinjam);
                indexBukuDipinjam -= 1;
                fflush(stdin);
                printf("Masukan Nama Peminjam :");
                scanf("%[^\n]",peminjam.namaPeminjam);
                fflush(stdin);
                daftarBuku[indexBukuDipinjam].jumlahBuku -= 1;
                strcpy(peminjam.judulBuku,daftarBuku[indexBukuDipinjam].judul);
                daftarPeminjam[indexDaftarPeminjam] = peminjam;
                indexDaftarPeminjam++;
                break;
            case 5:
                for (int i = 0; i < indexDaftarPeminjam; ++i) {
                    printf("%i. %s [%s]",i+1,daftarPeminjam[i].namaPeminjam,daftarPeminjam[i].judulBuku);
                    if (i != indexDaftarPeminjam){
                        printf("\n");
                    }
                }
                break;
            case 6:
                printf("Masukan Nomor Peminjam:");
                scanf("%d", &indexPengembalian);
                indexPengembalian -= 1;
                indexBukuDikembalikan = findIndexBuku(daftarBuku,indexDaftarBuku,daftarPeminjam[indexPengembalian].judulBuku);
                for (int i = indexPengembalian; i < indexDaftarPeminjam+1; ++i) {
                    if(i + 1 != indexDaftarPeminjam+1){
                        daftarPeminjam[i] = daftarPeminjam[i+1];
                    }
                }
                indexDaftarPeminjam -= 1;
                daftarBuku[indexBukuDikembalikan].jumlahBuku += 1;
                break;
            case 7:
                isRun = false;
                printf("Program Exited.");
                break;
            default:
                printf("Tidak ada angka %i di menu",pilihan);
                break;
        }
        printf("\n");
    }
}
