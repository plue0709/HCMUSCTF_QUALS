Đề bài là 1 File APK, chạy file thì đây là một chương trình checkflag, nếu nhập flag đúng thì sẽ báo valid hoặc ngược lại

![image](https://user-images.githubusercontent.com/80806913/168503047-585798dd-8796-4166-86ae-d0e123ac02d7.png)

Sử dụng jadx để reverse file, trong source code của file có thư mục example.babydroid chứa hàm và các điều kiện của flag

![image](https://user-images.githubusercontent.com/80806913/168503161-3d32bf80-fbcb-42e5-862e-ebb211ec4d33.png)

Điều kiện của flag:
        **if (flag.startsWith("HCMUS-CTF{") && flag.charAt(19) == '_' && flag.length() == 37 && flag.toLowerCase().substring(10).startsWith("this_is_") && flag.charAt(((int) (MagicNum.obtainY() * Math.pow(MagicNum.obtainX(), MagicNum.obtainY()))) + 2) == flag.charAt(((int) Math.pow(Math.pow(2.0d, 2.0d), 2.0d)) + 3) && new StringBuilder(flag).reverse().toString().toLowerCase().substring(1).startsWith(ctx.getString(R.string.last_part)) && new StringBuilder(flag).reverse().toString().charAt(0) == '}' && Helper.ran(flag.toUpperCase().substring((MagicNum.obtainY() * MagicNum.obtainX() * MagicNum.obtainY()) + 2, (int) (Math.pow(MagicNum.obtainZ(), MagicNum.obtainX()) + 1.0d))).equals("ERNYYL") && flag.toLowerCase().charAt(18) == 'a' && flag.charAt(18) == flag.charAt(28) && flag.toUpperCase().charAt(27) == flag.toUpperCase().charAt(28) + 1) {**


Đơn giản hóa điều kiện sử dụng các class khác như MagicNum, Helper ta được: 

![image](https://user-images.githubusercontent.com/80806913/168532014-2e1294b0-72d7-4f8c-9216-6f9930f246f1.png)


Nhìn qua một lần các điều kiện trên tại các dòng 1,2,3,4,9, ta có được chiều dài flag là 37 và một phần của flag là: **HCMUS-CTF{this_is_a_really**


**Helper.ran(flag.toUpperCase().substring(20, 26)).equals("ERNYYL")** điều kiện này cho biết ký tự flag từ 20 đến 26, chạy hàm ran trong class Helper với tham số truyền vào 
là ký tự 20 đến 26 mà input flag mình nhập vào, sao cho kết quả trùng với "ERNYYL"

![image](https://user-images.githubusercontent.com/80806913/168524777-f8d3e69f-0c8a-4e7a-a396-96aa50d8819a.png)

Để lấy được ký tự flag ta chạy đoạn code trên với tham số truyền vào là chuỗi "ERNYYL" ta được "really". **HCMUS-CTF{this_is_a_really**

**new StringBuilder(flag).reverse().toString().toLowerCase().substring(1).startsWith(ctx.getString(R.string.last_part))** điều kiện này ý nghĩa là đảo ngược phần từ sát phần tử cuối
kiểm tra bằng với ctx.getString(R.string.last_part). và tìm kiếm last_part trong source code ta được:

![image](https://user-images.githubusercontent.com/80806913/168525188-eaf25be1-7373-4881-93ee-66ae31027192.png)


last_part = ver_sic, đảo ngược lại là **sic_rev**. Từ đây và điều kiện cuối ta có flag: **HCMUS-CTF{this_is_a_really_basic_rev}**

Nhưng khoannnnnnn, Regex here. Chương trình sẽ kiểm tra flag từ ký tự 10 đến 36 có thỏa regex hay không.

![image](https://user-images.githubusercontent.com/80806913/168525369-99167aa8-fd75-4555-b1b1-a68ef482e98d.png)

Kiểm tra kết quả của Result ta được mẫu: [A-Z_][a-z_]
Sử dụng https://regex101.com/ để check ta được flag:

![image](https://user-images.githubusercontent.com/80806913/168526198-a545d703-a653-45a6-91c2-0cd7afdf5a13.png)


![image](https://user-images.githubusercontent.com/80806913/168526344-ad98beed-9640-42c9-ba97-1a0e8049e4af.png)


**HCMUS-CTF{ThIs_iS_A_ReAlLy_bAsIc_rEv}**




