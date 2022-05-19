#ifndef _COPIA_H_
#define _COPIA_H_

template<class CE> class Copia{
    private:
        Copia<CE> *pProx;
        Copia<CE> *pAnte;
        CE* copia;
    public:
        Copia();
        ~Copia();
        void setProx(Copia<CE>*prox){pProx=prox;}
        Copia<CE>*getProx(){return pProx;}

        void setAnte(Copia<CE>*ante){pAnte=ante;}
        Copia<CE>*getAnte(){return pAnte;}

        void setCopia(CE* cop){ copia=cop;}
        CE* getCopia(){return copia;}

        Copia<CE> *operator++() { 
        }
        
};

template <class CE> 
inline Copia<CE>::Copia(){
    pProx=NULL;
    copia=NULL;
}

template <class CE>
inline Copia<CE>::~Copia(){
    pProx=NULL;
    copia=NULL;
}
#endif