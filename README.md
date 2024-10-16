# Tugas Sistem Mikroprosesor #1: GPIO
Kode pada tugas ini dibuat untuk compiler Arduino IDE menggunakan bahasa C-Lite.

1. Lampu Kedip (Blinking LED)
Deskripsi Masalah:
Buat sebuah sistem yang menyalakan dan mematikan LED dengan pola kedip (blinking) menggunakan periode lebih dari 1 detik dan duty cycle yang tidak sama dengan 50%. Untuk memvalidasi, lakukan pengukuran periode dan duty cycle menggunakan analisis video.
Spesifikasi Kode:
Kode ini menghasilkan pola kedip LED dengan periode T = 2400ms (2.4 detik) dan duty cycle 33.3%. LED menyala selama 800ms dan mati selama 1600ms dalam setiap siklus.

2. Implementasi Persamaan Boolean
Deskripsi Masalah:
Implementasikan tiga fungsi logika dengan 3 input (dari tombol) dan 1 output (LED) menggunakan ESP32. Persamaan Boolean yang diimplementasikan adalah:
a) Gerbang AND dengan 3 input
b) Gerbang OR dengan 3 input
c) Persamaan logika bebas (dalam hal ini dipilih gerbang XOR) dengan 3 input
Spesifikasi Kode:
Kode ini memungkinkan pengguna memilih mode operasi logika (AND, OR, atau XOR) melalui Serial Monitor (dengan input 1, 2, atau 3). Tombol digunakan untuk memberikan sinyal input ke persamaan logika yang dipilih, dan LED akan menyala atau mati berdasarkan hasil logika tersebut.
Jika push-button tidak tersedia, input dapat diganti dengan sinyal HIGH dan LOW menggunakan kabel yang disambungkan ke sumber daya dan ground melalui resistor pembatas arus.

3. Sistem Interupsi
Deskripsi Masalah:
Buat sistem dengan dua tombol input dan satu LED output dengan perilaku interupsi sebagai berikut:
a) Tombol pertama untuk menyalakan LED, dan tombol kedua untuk mematikan LED.
b) Perilaku bebas, dengan minimal satu input dan satu output.
Spesifikasi Kode:
Kode ini memanfaatkan interupsi pada ESP32 untuk merespon input dari tombol secara cepat.
Tombol 1 (pin D5): Menyala atau mengaktifkan LED.
Tombol 2 (pin D18): Mematikan LED.
Tombol 3 (pin D19): Mengaktifkan mode blinking dengan interval 500ms (untuk opsi b).
Sistem wiring menggunakan mode INPUT_PULLUP, sehingga tombol dihubungkan ke ground, dan ketika tombol ditekan, sinyal menjadi LOW.
