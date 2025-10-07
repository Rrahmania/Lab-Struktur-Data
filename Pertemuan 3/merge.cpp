#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk menggabungkan dua subarray yang sudah terurut
void merge(vector<int>& arr, int left, int mid, int right) {
   
    // Menghitung ukuran dua subarray yang akan digabungkan
    int n1 = mid - left + 1;  // Ukuran subarray kiri
    int n2 = right - mid;     // Ukuran subarray kanan

    // Membuat array sementara untuk menyimpan kedua subarray
    vector<int> L(n1), R(n2);

    // Menyalin data ke array sementara L[] (kiri)
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    // Menyalin data ke array sementara R[] (kanan)
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Inisialisasi indeks untuk iterasi
    int i = 0;   // Indeks awal subarray kiri
    int j = 0;   // Indeks awal subarray kanan
    int k = left; // Indeks awal subarray yang akan digabungkan

    // Menggabungkan array L dan R kembali ke arr[]
    while (i < n1 && j < n2) {
        // Memilih elemen yang lebih kecil dari kedua subarray
        if (L[i] <= R[j]) {
            arr[k] = L[i];  // Masukkan elemen dari subarray kiri
            i++;            // Pindah ke elemen berikutnya di kiri
        } else {
            arr[k] = R[j];  // Masukkan elemen dari subarray kanan
            j++;            // Pindah ke elemen berikutnya di kanan
        }
        k++;  // Pindah ke posisi berikutnya di array utama
    }

    // Menyalin sisa elemen dari L[] jika ada
    while (i < n1) {
        arr[k] = L[i];  // Salin elemen yang tersisa dari kiri
        i++;            // Increment indeks kiri
        k++;            // Increment indeks array utama
    }

    // Menyalin sisa elemen dari R[] jika ada
    while (j < n2) {
        arr[k] = R[j];  // Salin elemen yang tersisa dari kanan
        j++;            // Increment indeks kanan
        k++;            // Increment indeks array utama
    }
}

// Fungsi utama merge sort yang menggunakan divide and conquer
void mergeSort(vector<int>& arr, int left, int right) {
   
    // Base case: jika subarray hanya memiliki 1 elemen atau kurang
    if (left >= right)
        return;  // Tidak perlu diurutkan

    // Mencari titik tengah untuk membagi array
    int mid = left + (right - left) / 2;

    // Rekursi: mengurutkan separuh kiri array
    mergeSort(arr, left, mid);
    // Rekursi: mengurutkan separuh kanan array
    mergeSort(arr, mid + 1, right);
   
    // Menggabungkan dua subarray yang sudah terurut
    merge(arr, left, mid, right);
}

// Fungsi untuk mencetak array
void printArray(const vector<int>& arr) {
    // Iterasi melalui semua elemen array
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";  // Cetak setiap elemen diikuti spasi
    }
    cout << endl;  // Pindah ke baris baru setelah selesai
}

// Fungsi utama program
int main() {
    int n;  // Variabel untuk menyimpan jumlah elemen
    cout << "Masukkan jumlah elemen data: ";  // Prompt input
    cin >> n;  // Membaca jumlah elemen dari user
   
    vector<int> data(n);  // Membuat vector dengan ukuran n
    cout << "Masukkan elemen-elemen data: ";  // Prompt input
    // Loop untuk membaca setiap elemen data
    for (int i = 0; i < n; i++) {
        cin >> data[i];  // Membaca elemen ke-i
    }
   
    // Menampilkan array sebelum diurutkan
    cout << "Array sebelum diurutkan: ";
    printArray(data);  // Memanggil fungsi printArray
   
    // Memanggil mergeSort untuk mengurutkan array
    mergeSort(data, 0, n - 1);  // Parameter: array, indeks awal, indeks akhir
   
    // Menampilkan array setelah diurutkan
    cout << "Array setelah diurutkan: ";
    printArray(data);  // Memanggil fungsi printArray
   
    return 0;
}