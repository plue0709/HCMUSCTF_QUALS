Đề cho 1 file thực thi **timehash**. Cùng xem bên trong có gì

![image](https://user-images.githubusercontent.com/80806913/168526970-9871ace5-bcb7-483d-b75d-4bc0129a5536.png)

Hiểu đơn giản Khi chạy chương trình v4 được gán **v4 = 573785173** và nếu **v4 > 268435456** thì **v4 = SeriousHash(v4)**

Xem hàm **SeriousHash()** có gì

![image](https://user-images.githubusercontent.com/80806913/168527641-9bce44ae-20e6-47fc-87f4-9735eda30e5c.png)

Cộng, nhân, xor, dịch bit trái phải và một hàm **HIWORD**

Cùng đi hỏi GOOGLE về **HIWORD** 

![image](https://user-images.githubusercontent.com/80806913/168529444-f4d13539-ca37-4939-8064-63a7e68dbb3a.png)

Hiểu đơn giản thì **HIWORD** một số là bỏ đi phần bit HIGH của số là bỏ đi 1 WORD bên phải của số
Ví dụ: **573785173** dạng binary là                 **00100010001100110100010001010101**
        **HIWORD(573785173) = 8755** dạng binary là **0010001000110011**
 
 Đưa hàm **SeriousHash**, **HIWORD**, chạy chương trình và tìm **v4**
 
![image](https://user-images.githubusercontent.com/80806913/168530029-8cdd4540-c7ed-43c6-ac52-ee61cce12535.png)

![image](https://user-images.githubusercontent.com/80806913/168530158-921de48b-e26b-4393-b013-0a90f2bbfa33.png)

**HCMUS-CTF{96521168}**

