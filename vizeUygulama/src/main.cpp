/* Kullanıcı tarafından girilecek 10 elemanlı dz[] dizi oluşturun.
    Sonra bu dizinin içideki 2 ile bölünebilen sayılar sayısı kadar
    dinamik arr[] dizisi oluşturun.
    Sonra bu dz[] dizisindeki 2 ile bölünebilen sayıları stack yardımı ile sıralayark arr[] dizisine atın ve arr dizisini yazdırın*/

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class stack{
public:
stack(int kapasite){
    this->kapasite = kapasite;
    top = -1;
    veriler = new int[kapasite];
}
void push(int arr){
    if(top<kapasite-1){
        top++;
        veriler[top] = arr;
    }
}
void pop(){
    if(top!=-1) top--;
}
int topDeger(){
    return veriler[top];
}
void yazdir(){
    for (int i = 0;i<=top;i++)
    {
        cout<<veriler[i]<<endl;
    }
    
}
bool isEmpty(){
    if(top == -1) return true;
    
    return false;
}

private:
    int top;
    int* veriler;
    int kapasite;
};


int recursive(int sayi){
    if(sayi == 0)return 0;              //recursive kullanarak parametre olarak verilen sayıya kadar olan sayıları toplama

    return sayi + recursive(sayi-1);
}


                
int main(){

    int dz[10];
    int sayac = 0;//sayac bize dz[]'nin içinde ne kadar 2 ye bölünebilen sayı var onu göstericek böylece heapten ne kadar alan alacağımızı bileceğiz
    for (int i = 0; i < 10; i++)
    {
        int veri;
        cout<<i<<"inci indexi girin:";      //Burada kullanıcıdan değerleri alıyoruz
        cin>>veri;
        if(veri%2 == 0)sayac++;
        dz[i] = veri;
    }
    int* arr = new int[sayac];
    stack* sortedStack = new stack(sayac);
    stack* tempStack = new stack(sayac);
    
    for (int i = 0; i < 10; i++)
    {
        if(dz[i]%2 == 0){ //bu if' te dz[] içinde 2 ye bölünemeyenleri elemiş oluyoruz.
            if(sortedStack->isEmpty()){ //stackte hiç eleman yoksa direk ilk elemanı ekliyoruz.
                sortedStack->push(dz[i]);
                continue;
            } 
           
            if(sortedStack->topDeger() <= dz[i]){               /* Eğer gelen değer sortedStacktekinden büyükse sortedStack deki değerlei, gelen değer
                                                                    sortedStackteki topDegerden küçük olana kadar sortedStackdeki değerleri  geçici olan tempStacke koyuyoruz
                                                                    sortedStack de gelen değere uygun olan yeri bulup ekledikten sonra tempStack deki değerleri bir daha sortedStacke atıyoruz*/
                
                while(sortedStack->topDeger() <= dz[i]){
                    tempStack->push(sortedStack->topDeger());
                    sortedStack->pop();
                }
                sortedStack->push(dz[i]); //sortedStack deki elemanları çıkardıktan sonra gelen değere yer bulup atadığımız kısım.
                while(!tempStack->isEmpty()){ // buarda yukarda dediğim gibi temp deki elemanları geri bi daha sortedStacke atıyoruz.
                    sortedStack->push(tempStack->topDeger());
                    tempStack->pop();
                }
            }
            else{ // else durumunda zaten direk sıralı olan sortedStacke atıyoruz.
                sortedStack->push(dz[i]);
            }
        
        }
    }
    sortedStack->yazdir(); //stack te sıralandığını göstermek için yazdırdım.
    cout<<"---------------------------------"<<endl;
    for (int i = 0; i < sayac; i++)
    {                                   //fazladan kod olmaması için arr[] dizinin içine değerleri atarken aynı zamanda yazdırdım. Zaten kontrol amaçlı yazdırıyoruz.
        arr[i] = sortedStack->topDeger();
        cout<<arr[i]<<endl;
        sortedStack->pop();
    }
    

    
    
    
}
