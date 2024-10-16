
# Tugas Sistem Mikroprosesor #1: GPIO

Kode pada tugas ini dibuat untuk compiler Arduino IDE menggunakan bahasa C-Lite.

## 1. Lampu Kedip (Blinking LED)
**Deskripsi Masalah:**
Membuat sebuah sistem yang menyalakan dan mematikan LED dengan pola kedip (blinking) menggunakan periode lebih dari 1 detik dan duty cycle yang tidak sama dengan 50%. Untuk memvalidasi hasil, lakukan pengukuran periode dan duty cycle menggunakan analisis video.

**Spesifikasi Kode:**
Kode ini menghasilkan pola kedip LED dengan periode **T = 2400ms (2.4 detik)** dan **duty cycle 33.3%**. LED menyala selama **800ms** dan mati selama **1600ms** dalam setiap siklus.

---

## 2. Implementasi Persamaan Boolean
**Deskripsi Masalah:**
Mengimplementasikan tiga fungsi logika dengan 3 input (tombol) dan 1 output (LED) menggunakan ESP32. Persamaan Boolean yang diimplementasikan adalah:

- a) Gerbang **AND** dengan 3 input
- b) Gerbang **OR** dengan 3 input
- c) Gerbang **XOR** dengan 3 input (persamaan logika bebas)

**Spesifikasi Kode:**
Kode ini memungkinkan pengguna memilih mode operasi logika (AND, OR, atau XOR) melalui **Serial Monitor** dengan input 1, 2, atau 3. Tombol digunakan sebagai sinyal input untuk persamaan logika yang dipilih, dan LED akan menyala atau mati berdasarkan hasil logika tersebut.

Apabila push-button tidak tersedia, input dapat diganti dengan sinyal **HIGH** dan **LOW** menggunakan kabel yang disambungkan ke sumber daya dan ground dengan resistor pembatas arus.

---

## 3. Sistem Interupsi
**Deskripsi Masalah:**
Membuat sistem dengan dua tombol input dan satu LED output dengan mekanisme interupsi, yang berperilaku sebagai berikut:

- a) Tombol pertama untuk **menyalakan** LED, dan tombol kedua untuk **mematikan** LED.
- b) Mode tambahan bebas (dalam tugas ini tidak diimplementasikan).

**Spesifikasi Kode:**
Kode ini memanfaatkan mekanisme interupsi pada ESP32 untuk merespon input dari tombol secara cepat.

- **Tombol 1 (pin D5):** Menyalakan atau mengaktifkan LED.
- **Tombol 2 (pin D18):** Mematikan LED.
- **Tombol 3 (pin D19):** Mengaktifkan mode blinking dengan interval 500ms (untuk opsi b, tidak digunakan dalam tugas ini).

Sistem wiring tombol menggunakan mode **INPUT_PULLUP**, sehingga tombol dihubungkan ke ground, dan ketika tombol ditekan, sinyal berubah menjadi LOW.
