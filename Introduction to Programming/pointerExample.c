#include <stdio.h>
#include <stdlib.h>

int main(){
  int* p = NULL;
  int a = 5;
  
  //  p = Sadece bir değişken, özelliği bellek adresi tutması

  // *p = p değişkeninde tutulan adresteki içerik

  // &p = p değişkeninin KENDİ adresi

  //  p = &a Burada & işareti a değişkeninin bellek adresini verir
  //  p artık a değişkeninin bellek adresini tutuyor

  // Ama karıştırmayalım!

  // 1 - Pointer ler de bir değişkendir
  // 2 - Her değişkenin bir adresi ve bir değeri vardır
  // 3 - Pointer ların da adresi ve değeri (işaret ettiği adres değeridir) vardır

  p = &a;

  // Artık a nın içeriğine, daha doğrusu p nin işaret ettiği yerdeki içeriğe
  // *p diyerek ulaşabiliriz.
  
  printf("p nin işaret ettiği bellek adresi:\t\t p\t%p\n", p);
  printf("p nin işaret ettiği bellek adresindeki değer :\t *p\t%d\n", *p);
  printf("p nin kendisinin bellek adresi:   \t\t &p\t%p\n", &p);

  return 0;
}
