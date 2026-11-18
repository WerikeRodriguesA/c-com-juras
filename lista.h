    typedef struct lista Lista;

    Lista* px_lista (*next element);

    void lista_imprime(Lista* l);

//verificar se a lista está vazia 
    int lista_vazia(Lista* l);

//buscar um elemento na lista
    Lista* lista_busca(Lista* l, int v);