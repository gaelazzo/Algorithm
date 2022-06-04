#include <iostream>
#include <vector>
#include <tuple>


using namespace std;


namespace Algoritmi {
    /*
       https://www.hackerrank.com/challenges/pseudo-isomorphic-substrings/topics
        Suffix array A
        E' l'elenco ordinato dei suffissi di una stringa. Convenzionalmente si fa terminare la 
         stringa con un segno $, che è minore di ogni carattere della stringa
        L'array dei suffissi A pertanto contiene n+1 stringa di cui la prima fatta dal solo $

        Un suffix array può essere costruito eseguendo un attraversamento depth-first su un 
           suffix tree. Il suffix array in questo caso è l'elenco delle foglie nell'ordine
           in cui vengono trovate.
        
        E' stato dimostrato che qualsiasi algoritmo basato su un suffix tree può essere 
            sostituito da un algoritmo che usa una combinazione di un suffix array
            e di un LCP array. Il vantaggio di un suffix array è la minore occupazione di 
            spazio e che richiedono un tempo lineare di costruzione.

        Un suffix tree può essere costruito in un tempo lineare a partire da un suffix array
           e da un LCP array.

        Un ulteriore passo avanti verso la riduzione dello spazio è data dai suffix array 
           compressi e dagli indici BWT compressi come gli FM index.

        LCP array
        E' l'array che contiene le lunghezze dei più lunghi prefissi comuni di coppie 
            di elementi consecutivi di A (Suffix Array), con LCP[0] che viene posto
            convenzionalmente a n+1.


        Uno dei primi algoritmi per creare un suffix array è l'algoritmo SA-IS di Nong,Zhang
            e Chan (2009). Può essere ottimizzato per costruire contemporaneamente l'LCP array 

        L'implementazione di Yuta Mori supera la maggior parte degli altri algoritmi lineari e
           super lineari.
        

        Un utilizzo dei suffix array è per cercare tutte le occorrenza di una stringa in una stringa
         data. Questo può essere fatto con due ricerche binarie nel suffix array, una per trovare la
         posizione iniziale dell'intervallo e l'altra per la finale. 

    */

    /// <summary>
    /// Calcola l'elenco di tutte le posizioni di p in S dato il suffix array A
    /// Poiché il confronto ha costo O(n) l'algoritmo ha costo O((n^2)log(n))
    /// </summary>
    /// <param name="p"></param>
    /// <param name="S"></param>
    /// <param name="A"></param>
    /// <returns></returns>
    std::tuple<int, int> searchOccurrenciesNaive(char *p, char *S,
                std::vector<int> A) {
        int n = strlen(S);
        int p_len = strlen(p);
        /*
            Calcola s,r tali che l'intervallo A[s:r] rappresenta tutti i suffissi di S che
             iniziano con P (estremi inclusi)
        */
        //Cerca la posizione iniziale l
        int l = 0;
        int r = n;
        while (l < r) {
            int mid = (l + r) / 2; //arrotondato per difetto all'intero più vicino
            if (strcmp(p , S+A[mid] )>0) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        int s = l;

        //cerca la posizione finale r
        r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (strncmp(p, S + A[mid], p_len) > 0) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return { s, r };

    }
    
    

        

    std::vector<int> kasai(string s, vector<int> sa){
        int n = s.size(), k = 0;
        vector<int> lcp(n, 0);
        vector<int> rank(n, 0);

        for (int i = 0; i < n; i++) rank[sa[i]] = i;

        for (int i = 0; i < n; i++, k ? k-- : 0)
        {
            if (rank[i] == n - 1) { k = 0; continue; }
            int j = sa[rank[i] + 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
            lcp[rank[i]] = k;
        }
        return lcp;
    }

    
}


