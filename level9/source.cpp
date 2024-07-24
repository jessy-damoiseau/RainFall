#include <string.h>

class N{
    public:
        N(int nb): nb(nb){}
        ~N(){};
        N &operator+(N &tmp){
            this->nb =+ tmp.nb;
            return *this;
        }
        N &operator-(N &tmp){
            this->nb =- tmp.nb;
            return *this;
        }
        void setAnnotation(char *str){
            memcpy(buffer, str, strlen(str));
        };

        char buffer[108];
        int nb;
};

int main(int ac , char **av){
    if (ac < 1){
        N *var1 = new N(5);
        N *var2 = new N(6);
        int ret;
        var1->setAnnotation(av[1]);
        (**(void (***)(void))(var2))(var2, var1);
    }
}
