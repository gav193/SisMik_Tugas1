# SisMik_Tugas1
Tugas Sistem Mikroprosesor #1 GPIO
(Kode pada tugas ini dibuat untuk compiler Arduino IDE dengan bahasa C-Lite)

1. Lampu Kedip
   Deskripsi masalah : Membuat lampu kedip dengan perioda > 1 dan duty cycle != 50%. Ukur apakah perioda dan duty cycle cocok dengan menggunakan analisis video.
   Spesifikasi kode : Kode ini berfungsi untuk mengeluarkan nyala LED dengan pola blinking dengan perioda T = 2400ms (2.4 detik) dan duty cycle 33.3% (menyala 800ms dari 2400ms).

2. Persamaan Boolean
   Deskripsi masalah : Membuat implementasi persamaan boolean 3 input, 1 output dengan ESP32. Input dengan tombol dan output dengan LED. Persamaan Boolean yang dibuat dibagi menjadi 3, yaitu :
   a) Gerbang AND 3 input
   b) Gerbang OR 3 input
   c) Persamaan logika bebas dengan 3 input dan 1 output
   Spesfikasi kode : Kode ini dibuat untuk mengeluarkan nyala LED sebagai output dari persamaan Boolean yang dipilih. Untuk bagian C, dipilih persamaan Boolean XOR. Cara menggunakannya adalah dengan memasukkan input pada serial monitor (1, 2, 3 yang berkorespondensi dengan fungsi a, b, c pada deskripsi masalah) untuk memilih mode operasi SAMBIL menekan tombol / memberi sinyal "HIGH" pada input apabila push-button tidak bekerja (alternatif dengan kabel yang disambung pada power supply dengan resistor pembatas arus sebagai sinyal HIGH dan ke ground sebagai sinyal LOW).

3. Interupsi
   Deskripsi masalah : Membuat sistem dengan input 2 tombol dan output minimal 1 LED dengan perilaku interupsi, yaitu :
   a) Satu tombol untuk mematikan LED, dan tombol lainnya untuk menyalakan LED
   b) Perilaku bebas, minimal 1 input dan 1 output.
   Spesifikasi kode : Kode ini dibuat untuk mengeluarkan nyala LED sebagai output untuk setiap perilaku interupsi. Interupsi dengan tombol pertama (pada pin D5) akan menyebabkan LED menyala. Interupsi dengan tombol kedua (pada pin D18) akan menyebabkan LED mati. Interupsi pada tombol ketiga untuk fungsi b (pada pin D19) akan menyebabkan LED blinking setiap 500ms. Sistem wiring tombol disini menggunakan internal pull-up sehingga button hanya perlu disambung pada ground dan pin input (button not pressed = HIGH signal, button pressed = connected to GND or LOW signal).
