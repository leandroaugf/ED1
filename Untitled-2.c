
struct labirinto {

    char **lab;
    int lins;
    int cols;

};

/*TAD que armazena as coordenadas de posicao do labirinto*/
struct posicao {
  
    int x;
    int y;

};

typedef struct {
    Posicao posicao;
} Item;

typedef struct celula {
    Item item;
    struct celula *prox;
} Celula;

struct pilha {
    int tamanho;
    Celula *topo;
    Celula *cabeca;
}

struct fila { // implementado como uma lista 
    int tamanho;
    Celula *cauda;
    Celula *cabeca;
    // item na celula = posicao;
};

struct percurso {

    Posicao** posicao_saida;
    int tamanho;

};

// ======================================================================= [ PILHA ] ==============================================================================
//                                                                                                                                           BUSCA EM PROFUNDIDADE 

void iniciaPilha() {
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));

    pilha->cabeca = (Celula *) malloc(sizeof(Celula));
    // init
    pilha->cabeca->prox = NULL;
    pilha->cabeca->item->x = 0;
    pilha->cabeca->item->y = 0;
    
    pilha->topo = pilha->cabeca;

    pilha->tamanho = 0;

    return pilha;
}

int pilhaEhVazia(pilha *pilha) {
    return (pilha->cabeca->prox == NULL);
}

// [ADICIONA UM ELEMENTO AO TOPO] -- NOTA: "topo" não faz parte da lista, é como um clone;
// DEPOIS TROCAR P/ BOOL -> RETORNAR SE FOI POSSÍVEL INSERIR OU NÃO
void pilhaPush(Pilha *pilha, Posicao pos) {
    Celula *cel = malloc(sizeof(Celula));
    if (cel == NULL)
        return;

    cel->item->x = pos.x;
    cel->item->y = pos.y;

    cel->prox = NULL;
    pilha->topo->prox = cel;
    pilha->topo = cel;

    return;
}

// [RETIRA O ELEMENTO DO TOPO]
int pilhaPop(Pilha *pilha) {
    if (pilhaEhVazia(pilha))
        return NULL;
    Celula *aux = pilha->cabeca;
    while (aux->prox->prox != NULL) // para qdo estver uma posição anterior ao topo
        aux = aux->prox;
    // libero o topo e o atualizo
    free(topo);
    topo = aux;
    aux->prox = NULL;

    return 1;
}


















//=================================================================================================================================================================

//=================== [NOTA: A FUNÇÃO SEMPRE CONFERE O ITEM DO TOPO DA PILHA] =====================================================================================

//=================================================================================================================================================================













    for (int i = 0; i < labirinto->lins; i++) 
        for (int j = 0; j < labirinto->cols; j++) 
            if (labirinto[i][j] == ' ')
                labirinto[i][j] = '0';



******






// REQUISITOS: RECEBER A POSIÇÃO INICIAL E O LABIRINTO COM OS CAMINHOS NÃO VISITADOS // 
void acharSaidaPilha(Pilha *pilha, Labirinto *labirinto, Posicao posicao) {
    Posicao posicao;
    posicao.x = pilha->topo->item->x; 
    posicao.y = pilha->topo->item->y;

    // CONDIÇÃO DE VITÓRIA AQUI
    // {...}

//  [MARCAÇÃO DOS ESPAÇOS NÃO VISITADOS] --- ESTÁ NA FUNÇÃO ERRADA --- 


//  [ABA DE TRACKING DO LABIRINTO]

//  [DIREITA]
    if (labirinto[pilha->topo->item->x][pilha->topo->item->y + 1] == '0') {
        labirinto[i][j] = '1';
        posicao.x = posicao.x;
        posicao.y = posicao.y + 1;
        pilhaPush(pilha, posicao);
    }

//  [BAIXO]
    if (labirinto[pilha->topo->->x + 1][pilha->posicao->y] == '0') {
        labirinto[i][j] = '1';
        posicao.x = posicao.x;
        posicao.y = posicao.y + 1;
        pilhaPush(pilha, posicao);
    }
    
//  [ESQUERDA]
    if (labirinto[pilha->posicao->x][pilha->posicao->y - 1]) {
        labirinto[i][j] = '1';
        posicao.x = posicao.x;
        posicao.y = posicao.y + 1;
        pilhaPush(pilha, posicao);
    }

//  [CIMA]
    if (labirinto[pilha->posicao->x - 1][pilha->posicao->y + 1]) {
        posicao.x = posicao.x;
        posicao.y = posicao.y + 1;
        pilhaPush(pilha, posicao);
    }
}

// [RETORNA AS COORDENADAS INICIAIS DO RATO]
Posicao primeiraPosicao(Labirinto *labirinto) {
    Posicao firstpos;
    for (int i = 0; i < labirinto->lins; i++)
        for(int j = 0; j < labirinto->cols; j++)
            if (labirinto[i][j] == 'M') {
                firstpos.x = lins;
                firstpos.y = cols;
            }

    return firstpos;
}

// ======================================================================= [ FILAS ] ==============================================================================
//                                                                                                                                                 BUSCA EM LARGURA
Fila filaInicia() {

    Fila *fila = malloc(sizeof(Fila));

    fila->cabeca = malloc(sizeof(Celula));
    fila->cauda = fila->cabeca;
    fila->tamanho = 0;

    return fila;
}

int acharSaidaFila(Labirinto* labirinto, Fila *fila, ) {
    // nao pega as bordas do labirinto
    for (int i = 1; i < labirinto->lins - 1; i++) {
        for (int j = 1; j < labirinto->cols - 1; j++) {
            if (labirinto[i][j] == ' ')
                labirinto[i][j] = 0;
        }
    }

    desenfileirar(fila);

}

void desenfileirar(Fila *fila) { // o "item" é o elem. mais antigo da fila (r.u.)
    // [FILA VAZIA]
    if (fila->cabeca->prox == NULL) 
        return NULL;
    Celula *aux = (Celula*) malloc(sizeof(Celula));
    // procedimento p/ liberar um elemento;
    aux = fila->cabeca->prox;
    free(fila->cabeca->prox);
    fila->cabeca->prox = aux;
    enfileirar(fila);
} 

int enfileirar(Fila *fila, Labirinto *labirinto) {
//  [DIREITA]
    if (labirinto[fila->posicao->x][fila->posicao->y + 1] == '0') { // NAO VISITADO
        Celula *movedir = (Celula *) malloc(sizeof(Celula));
        if(movedir == NULL)
            return -1;
        fila->cauda->prox = movedir;
        fila->cauda = movedir;
        movedir->prox = NULL;
    }

//  [BAIXO]
    if (labirinto[fila->posicao->x + 1][fila->posicao->y] == '0') { // NAO VISITADO
        Celula *movebai = (Celula *) malloc(sizeof(Celula));
        if(movebai == NULL)
            return -1;
        fila->cauda->prox = movebai;
        fila->cauda = movebai;
        movebai->prox = NULL;
    }

//  [ESQUERDA]
    if (labirinto[fila->posicao->x][fila->posicao->y - 1] == '0') { // NAO VISITADO
        Celula *moveesq = (Celula *) malloc(sizeof(Celula));
        if(moveesq == NULL)
            return -1;
        fila->cauda->prox = moveesq;
        fila->cauda = moveesq;
        moveesq->prox = NULL;
    }

//  [CIMA]
    if (labirinto[fila->posicao->x - 1][fila->posicao->y] == '0') { // NAO VISITADO
        Celula *movecim = (Celula *) malloc(sizeof(Celula));
        if(movecim == NULL)
            return -1;
        fila->cauda->prox = movecim;
        fila->cauda = movecim;
        movecim->prox = NULL;
    }

    return 1;
}
