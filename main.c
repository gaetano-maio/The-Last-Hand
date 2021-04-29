/*  _________   ___  ___   _______           ___        ________   ________   _________        ___  ___   ________   ________    ________     
   |\___   ___\|\  \|\  \ |\  ___ \         |\  \      |\   __  \ |\   ____\ |\___   ___\     |\  \|\  \ |\   __  \ |\   ___  \ |\   ___ \    
   \|___ \  \_|\ \  \\\  \\ \   __/|        \ \  \     \ \  \|\  \\ \  \___|_\|___ \  \_|     \ \  \\\  \\ \  \|\  \\ \  \\ \  \\ \  \_|\ \   
        \ \  \  \ \   __  \\ \  \_|/__       \ \  \     \ \   __  \\ \_____  \    \ \  \       \ \   __  \\ \   __  \\ \  \\ \  \\ \  \ \\ \  
         \ \  \  \ \  \ \  \\ \  \_|\ \       \ \  \____ \ \  \ \  \\|____|\  \    \ \  \       \ \  \ \  \\ \  \ \  \\ \  \\ \  \\ \  \_\\ \ 
          \ \__\  \ \__\ \__\\ \_______\       \ \_______\\ \__\ \__\ ____\_\  \    \ \__\       \ \__\ \__\\ \__\ \__\\ \__\\ \__\\ \_______\
           \|__|   \|__|\|__| \|_______|        \|_______| \|__|\|__||\_________\    \|__|        \|__|\|__| \|__|\|__| \|__| \|__| \|_______|     
                                                                  \|_________|                                                                  */
										
										//************ -  The Last Hand  - ************************/				       				  								
										/* Author: Vincenzo Intorcia, Gaetano Maio				  */
										/* Team: Faithful Dog				   				      */
										/* Version: 2.0							  				  */
										/* last compilation: 14/03/2021			  				  */
										//*********************************************************/

//************ - #LiBRERIE# - *****************************/
											              //
	#include <stdio.h>                                    //          
	#include <stdlib.h>	   		  			              //
	#include <time.h>	   					              //
	#include <windows.h>								  // Libreria per introdurre le system call.
											   			  //
//********************************************************/
											   
//************ - {FUNZIONI} - ****************************/
											   			 //
 	void score (int *, int *);                           //	score: funzione che prende in input i punti, e li elabora in caso di vincita, sconfitta e pareggio.			
 													     // 
   /**- IMPOSTAZIONI -**/								 //
    													 //
	void settings  (void);								 // settings: funzione che richiama altre impostazioni in base alla scelta del giocatore.
 	void SETwindow (void);								 // SETwindow: impostazioni della finstra del cmd.
 	void SETtheme  (void);								 //	SETtheme: impostazioni pe settare un tema.							 
														 //
	void alfred    (void);								 // alfred: un robottino che presenta The Last Hand.
	void loading   (void);								 // loading: simula un caricamento all'avvio del gioco.
	void gameboy   (void);								 // gameboy: logo del gioco.
	void rules     (void);								 // rules: regole del gioco
													     //														 
	void rock     (void);								 // rock: sasso in ASCII 
	void paper    (void);					             // paper: carta in ASCII 
	void scissors (void);							     // scissors: forbice in ASCII 
	 													 //
	/**- FORMATTAZIONE -**/								 //												 
	void spaziorizzontali (int); 						 // spaziorizzontali: formatta il testo in base alla finestra
	void spaziverticali (int);							 // spaziverticali: formatta il testo, mettendo degli spazi verticali
														 //
 	void setcolor(unsigned short color)					 // setcolor: modifica il colore delle stringhe in base al paramentro.
 	{													 //
 	   HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);    //
       SetConsoleTextAttribute(hCon,color);			     //
 	}													 //
	 													 //	 								   					 
//*******************************************************/

//************ - GLOBALI & COSTANTI - ******************//
													    //
													    //
	int P1, P2;    	 							        // P1/P2: punti del NPC e dell'utente/videogiocatore.
	int n;										        // n: valore costante, per formattare il testo in base alla finestra.
				   									    //
	enum legendainput							 	    // legendainput: enumerazione, per il controllo dell'input (giocate).
	{											 	    //
	 	sasso=1,									    //
	 	carta,			 //PARTITA					    //
	 	forbice,									    //
	 												    //
	};												    //
//*****************************************************//		    	


int main(int argc, char *argv[]){
	
	
//************ - #INTERI# - *******************************/
											              //
	int G1, G2;	                                          // G1 e G2 sono le giocate, mosse (Sasso=1, Carta=2, Forbice=3).       
	int i;   		  			                          // Contatore dei cicli for.
	int set1, set2;	   					                  //
	                     					              //
											   			  //
//********************************************************/
	
//************ - *PUNTATORI* - ****************************/
											              //
	int *pG1, *pG2;				                          // pG1/pG2: puntatore alle giocate.       
						   		  			              //
	pG1=&G1;											  //
	pG2=&G2;					   					      //
	 					 					              //
											   			  //
//********************************************************/
		
	srand(time(NULL));
				
	SETwindow();
	loading();

	alfred();
    fflush(stdin);
    
//****************- Dialogo con il robottino Alfred- ****************************************************/
											              												//
	setcolor(6);																					    //
	printf(" - Alfred: "); 													 	      fflush(stdin);    //
	setcolor(8);  																						//				 
	printf("Benvenuto sfidante!");													  getchar();		//												   	
								 												 				   	    //
	setcolor(6);                                                                                        //
	printf(" - Alfred: "); 											 		 		  fflush(stdin);    //
	                                                                                  setcolor(8);  	//				 
	printf("Sei ormai nel campo di battaglia, non puoi sfuggire alla tua sorte!");    getchar();   	    //
										 															    //
	setcolor(6);                                                                                        //
	printf("\n - Alfred: "); 											 		      fflush(stdin);    //
	setcolor(8);  																						//				 
	printf("Vinci la partita e aiutami a disinstallare i miei file dal gioco");       getchar();   	    //		                                                                                                //
																										//
	setcolor(6);                                                                                        //
	printf("\n - Alfred: "); 											 		 	  fflush(stdin);	//
																					  setcolor(8);  	//																									 
	printf("Seleziona: ");							 								  setcolor(5);		//					 	
	printf("Gioca [1] Regole [2]  ");   										      setcolor(6);		//						  
	scanf("%d",&G1);                                   			                                        //
										   			                                                    //
//******************************************************************************************************/					 				 
	
	if(G1<1||G1>2)
	{
	    do
		{
			setcolor(6); spaziverticali(1); 
			printf(" - Alfred: "); 											 		 		 
			setcolor(4);  																										 
			printf("SEGUI LA LEGENDA! SELEZIONE: "); setcolor(6);   
			scanf("%d",&G1);
		}
	    while(G1<1||G1>2);		//Verifica dell'input G1, controlla se minore di 1 o maggiore di 2, nel caso ripete il blocco di istruzioni.
	}	
	
	if(G1==2)
	{
		rules();
	}
		
    system("cls");
    
    setcolor(15);
    
//**************************************************************************************************************************************************************/		
			/*
				########     ###    ########  ######## #### ########    ###    
				##     ##   ## ##   ##     ##    ##     ##     ##      ## ##   
				##     ##  ##   ##  ##     ##    ##     ##     ##     ##   ##  
				########  ##     ## ########     ##     ##     ##    ##     ## 
				##        ######### ##   ##      ##     ##     ##    ######### 
				##        ##     ## ##    ##     ##     ##     ##    ##     ## 
				##        ##     ## ##     ##    ##    ####    ##    ##     ## 		*/

		do
		{		
		P1=0; P2=0;
			
		gameboy();

		for(i=1;i<=10;i++)
		{
		   G2=rand()%3+1;                       
		   
		   do
		   { 		   
		   spaziverticali(2); spaziorizzontali(n-2);
		   printf("    Sasso[1] Carta[2] Forbice[3] Impostazioni [4]");
		   
		   											spaziverticali(3); spaziorizzontali(n/2);
		   printf("G1 - score: %d", P1);         	spaziorizzontali(n);
		   printf("G2 - score: %d", P2);      	    spaziverticali(2); spaziorizzontali(n/2);
		   scanf("%d",&G1);

			if(G1<1||G1>4)
			{
			    do
				{
					spaziverticali(2); spaziorizzontali(n/3);
					printf("PREMI 1 PER SASSO, 2 PER CARTA, 3 PER FORBICE, BUONA FORTUNA!:");
					scanf("%d",&G1);
					spaziverticali(2);
				}
			    while(G1<1||G1>4);		//Verifica dell'input G1, controlla se minore di 1 o maggiore di 2, nel caso ripete il blocco di istruzioni.
			}
		
			if(G1==4)
			{
				settings();
			}	   
		    }
			while(G1==4);		   
					 			   
		   system("cls");
		   
		   spaziorizzontali(n);   
		   printf("The Last Hand - Round: %d", i); 		             spaziverticali(2); spaziorizzontali(n/2);
		   printf("G1 - score: %d", P1);      						 spaziorizzontali(n);
		   printf("G2 - score: %d", P2);      						 spaziverticali(2); 
		   		   
		   score(pG1, pG2);  	//Funzione che determina vincita, perdita e pareggio del singolo round (Riga 193)	   	    	
		}		

		system("cls"); 
		
		system("color 07");
		
		gameboy();

		spaziverticali(1); spaziorizzontali(n); 
		
		printf(" G1 = %d  -  %d  = G2", P1, P2); spaziverticali(2);
		
		if(P1==P2)
		{
			setcolor(8);
			printf(" - La partita si e' conclusa con un "); 
			setcolor(5);
		    printf("PAREGGIO! "); 
		    setcolor(8);
			printf("Se non sei soddisfatto, puoi riprovare"); fflush(stdin); getchar();	
			
		}
		else if(P1>P2)
		{	
			int j=0;
			
			for(i=0;j<99;i++)
			{	
				system("cls");
				alfred();
				
				setcolor(8);
				printf(" - La partita si e' conclusa con una "); 
				setcolor(2);
				printf(" VITTORIA! "); 
				setcolor(8);
				printf("Grazie per avermi liberato!\n"); 
				
				printf("\n * Avvio ");
				setcolor(4);
				printf("disinstallazione\n");				
				
				j=j+20;
				
				setcolor(8);	
				printf("\n - Stato ");				
				setcolor(4);
				printf("disinstallazione ");
				setcolor(6);					
				printf("[%d%%]", j);
				
				sleep(1);
			}			
			
			setcolor(2);
			printf("\n\n * Disinstallazione completata con successo: Alfred ti saluta :)"); fflush(stdin); getchar();
		}
		else
		{
			setcolor(8);
			printf(" - La partita si e' conclusa con una "); 
			setcolor(4);
		    printf("SCONFITTA! "); 
		    setcolor(8);
			printf("Non era il tuo momento, magari ti andra' meglio la prossima volta"); fflush(stdin); getchar();				
		}
		
		setcolor(15); 
		do
		{
		system("cls"); spaziorizzontali(n);
		printf("VUOI RIGIOCARE?");								    	spaziverticali(2); spaziorizzontali(n-2);			 	  								  		
		printf("Si' [1]  No [2]"); 		                                spaziverticali(2); spaziorizzontali(n-2);							   
		scanf("%d", &set1);	
	   											     																						
	    if(set1<1||set1>2)
		{
	        do
	    	{	
				spaziverticali(2); spaziorizzontali(n-2);
				printf("DIGITAZIONE ERRATA, PREMI UN TASTO SEGUENDO LA LEGENDA: ");
				scanf("%d",&set1);
			}
	    	while(set1<1||set1>2);	
	    }
				  														spaziverticali(2); spaziorizzontali(n-2);
		  printf("Conferma [1] Indietro [2]");						    spaziverticali(2); spaziorizzontali(n-2);
		  scanf("%d",&set2); 
		  
		  if(set2<1||set2>2)
			{
		        do
		    	{	
					spaziverticali(2); spaziorizzontali(n-2);
					printf("DIGITAZIONE ERRATA, PREMI UN TASTO SEGUENDO LA LEGENDA: ");
					scanf("%d",&set2);
				}
		    	while(set2<1||set2>2);		
			}
	     	}
			while(set2==2);
		
		system("cls");	
	    }
		while(set1==1);

	return 0;
}

//**************************************************************************************************************************************************************************************/		

 void spaziverticali (int n)
 {
	 	int i;
	 	for(i=1;i<=n;i++)
	 	{
	 		printf("\n");
		}
 }
 
//**************************************************************************************************************************************************************************************/		
 
 void spaziorizzontali (int n)
 {
	 	int i;
	 	for(i=1;i<=n;i++)
	 	{
	 		printf("\t");
		}
 }
 
//**************************************************************************************************************************************************************/		
 
  void SETwindow (void)
  {  
  
  	int set; 
	  	
    /*        _.-;;-._
      '-..-'|   ||   |
      '-..-'|_.-;;-._|
      '-..-'|   ||   |
      '-..-'|_.-''-._|		*/
    
    printf("       _.-;;-._	\n");
    printf("'-..-'|   ||   |\n");
    printf("'-..-'|_.-;;-._| Finestra piccola [Tasto 1] Finestra grande [Tasto 2]\n");
    printf("'-..-'|   ||   |\n");
    printf("'-..-'|_.-''-._|\n");
      
	printf("\n- "); scanf("%d",&set);
	    
	if(set<1||set>2)
	{
        do
    	{
    		setcolor(4);
			printf("\n - [Errore] SCRIVI 1 PER LA FINESTRA PICCOLA, 2 PER LO SCHERMO INTERO: ");
			scanf("%d",&set);
		}
    	while(set<1||set>2);	//Verifica dell'input G1, controlla se minore di 1 o maggiore di 2, nel caso ripete il blocco di istruzioni.		
	}
    
	system("cls");
	
    if(set==1)
    {
		n=6;	
	}
	else
	{
		n=11;	
	}	
	
 }
  
//**************************************************************************************************************************************************************/		

  void settings(void)
  {		
  		system("cls");
		int set1, set2;
  		
		do
		{														     	spaziorizzontali(n);
		   printf("SELEZIONA OPZIONI");								    spaziverticali(2); spaziorizzontali(n-2);			 	  								  		
		   printf("Finestra [1]  Tema [2]"); 		                    spaziverticali(2); spaziorizzontali(n-2);							   
		   scanf("%d", &set1);	
	   											     																						
	    if(set1<1||set1>2)
		{
	        do
	    	{	
				spaziverticali(2); spaziorizzontali(n-2);
				printf("DIGITAZIONE ERRATA, PREMI UN TASTO SEGUENDO LA LEGENDA: ");
				scanf("%d",&set1);
			}
	    	while(set1<1||set1>5);	
	    }
				  														spaziverticali(2); spaziorizzontali(n-2);
		  printf("Conferma [1] Indietro [2]");						    spaziverticali(2); spaziorizzontali(n-2);
		  scanf("%d",&set2); 
		  
		  if(set2<1||set2>2)
			{
		        do
		    	{	
					spaziverticali(2); spaziorizzontali(n-2);
					printf("DIGITAZIONE ERRATA, PREMI UN TASTO SEGUENDO LA LEGENDA: ");
					scanf("%d",&set2);
				}
		    	while(set2<1||set2>2);		
			}
		  
		  system("cls");
		}
		while(set2==2);

		if(set1==1)
		{
			SETwindow();
		}
		else
		{
			SETtheme();
		}
		
		system("cls");
  }
  
  
//**************************************************************************************************************************************************************/		

  void score(int *pG1 , int *pG2)
  {
  				
  		switch (*pG1)
  		{	
 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//    
 						       //SASSO//
	
    /*    _______
      ---'   ____)
            (_____)
            (_____)
            (____)
      ---.__(___)		*/

		case sasso:  //[Tasto 1]				
  			
        	if(*pG2==sasso)
  			{
  				
  				spaziorizzontali(n/2);
				printf("    _______"); 	   spaziorizzontali(n);
				printf("    _______\n");   spaziorizzontali(n/2);
				printf("---'   ____)");	   spaziorizzontali(n);
				printf("---'   ____)\n");  spaziorizzontali(n/2);
				printf("      (_____)");   spaziorizzontali(n);
				printf("      (_____)\n"); spaziorizzontali(n/2);
				printf("      (_____)");   spaziorizzontali(n);		
				printf("      (_____)\n");  spaziorizzontali(n/2);		
                printf("      (____)");     spaziorizzontali(n);
				printf("      (____)\n");    spaziorizzontali(n/2);
				printf("---.__(___)");     spaziorizzontali(n);		
				printf("---.__(___)\n");							
	  			
	  			spaziorizzontali(n-1);
	  			printf("SASSO (+0) - |PAREGGIO| - SASSO (+0)"); 
	  			
			}
			
			else if (*pG2==forbice)
			{
				
  				P1++;
  		
 				spaziorizzontali(n/2);
				printf("    _______"); 	   spaziorizzontali(n);
				printf("    _______\n");   spaziorizzontali(n/2);
				printf("---'   ____)");	   spaziorizzontali(n);
				printf("---'   ____)____\n");  spaziorizzontali(n/2);
				printf("      (_____)");   spaziorizzontali(n);
			 	printf("          ______)\n"); spaziorizzontali(n/2);
				printf("      (_____)");   spaziorizzontali(n);		
				printf("        __________)\n");  spaziorizzontali(n/2);		
                printf("      (____)");     spaziorizzontali(n);
				printf("      (____)\n");    spaziorizzontali(n/2);
				printf("---.__(___)");     spaziorizzontali(n);		
				printf("---.__(___)\n");							
	  			
	  			spaziorizzontali(n-1);	  			
	  			printf("SASSO (+1) - |VITTORIA| - FORBICE (+0)"); 		
	  			
			}
	
			else if (*pG2==carta)
			{
				
				P2++;
  										
				spaziorizzontali(n/2);
				printf("    _______"); 	  		 spaziorizzontali(n);
				printf("    _______\n");   		 spaziorizzontali(n/2);
				printf("---'   ____)");	         spaziorizzontali(n);
				printf("---'   ____)____\n");    spaziorizzontali(n/2);
			    printf("      (_____)");         spaziorizzontali(n);
				printf("          ______)\n");   spaziorizzontali(n/2);
				printf("      (_____)");         spaziorizzontali(n);		
				printf("          _______)\n");  spaziorizzontali(n/2);		
                printf("      (____)");     	 spaziorizzontali(n);
				printf("         _______)\n");   spaziorizzontali(n/2);
				printf("---.__(___)");     		 spaziorizzontali(n);		
				printf("---.__________)\n");							
	  			
	  			spaziorizzontali(n-1);
	  			printf("SASSO (+0) - |SCONFITTA| - CARTA (+1)"); 
				  				
			}

  			break;
  		
 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//    
						       //CARTA//

    /*    _______
      ---'   ____)____
                ______)
                _______)
               _______)
      ---.__________)		*/
						 
 		case carta:  //[Tasto 2]
  			
  			if(*pG2==carta)
  			{	
  			
				spaziorizzontali(n/2);
				printf("    _______");  spaziorizzontali(n);
				printf("    _______\n"); spaziorizzontali(n/2);
				printf("---'   ____)____"); spaziorizzontali(n-1);
				printf("---'   ____)____\n"); spaziorizzontali(n/2);
				printf("          ______)"); spaziorizzontali(n-1);
				printf("          ______)\n"); spaziorizzontali(n/2);
				printf("          _______)"); spaziorizzontali(n-1);
				printf("          _______)\n"); spaziorizzontali(n/2);
				printf("         _______)"); spaziorizzontali(n-1);
				printf("         _______)\n"); spaziorizzontali(n/2);
				printf("---.__________)");	spaziorizzontali(n);
				printf("---.__________)\n");
		 
	  			spaziorizzontali(n-1);	  			
	  			printf("CARTA (+0) - |PAREGGIO| - CARTA (+0)"); 
	  			
			}
  			
  			
			else if (*pG2==sasso)
			{
				
				P1++;
				
				spaziorizzontali(n/2);
				printf("    _______");  spaziorizzontali(n);
				printf("    _______\n"); spaziorizzontali(n/2);
				printf("---'   ____)____"); spaziorizzontali(n-1);
				printf("---'   ____)\n"); spaziorizzontali(n/2);
				printf("          ______)"); spaziorizzontali(n-1);
				printf("      (_____)\n"); spaziorizzontali(n/2);
				printf("          _______)"); spaziorizzontali(n-1);
				printf("      (_____)\n"); spaziorizzontali(n/2);
				printf("         _______)"); spaziorizzontali(n-1);
				printf("      (____)\n"); spaziorizzontali(n/2);
				printf("---.__________)");	spaziorizzontali(n);
				printf("---.__(___)\n");
				
	  			spaziorizzontali(n-1);	  			
	  			printf("CARTA (+1) - |VITTORIA| - SASSO (+0)"); 
				  					
			}
			
			else if (*pG2==forbice)
			{
				
				P2++;
			
				spaziorizzontali(n/2);
				printf("    _______");  spaziorizzontali(n);
				printf("    _______\n");   spaziorizzontali(n/2);
				printf("---'   ____)____"); spaziorizzontali(n-1);
				printf("---'   ____)____\n"); spaziorizzontali(n/2);
				printf("          ______)"); spaziorizzontali(n-1);
				printf("          ______)\n"); spaziorizzontali(n/2);
				printf("          _______)"); spaziorizzontali(n-1);
				printf("        __________)\n"); spaziorizzontali(n/2);
				printf("         _______)"); spaziorizzontali(n-1);
				printf("      (____)\n"); spaziorizzontali(n/2);
				printf("---.__________)");	spaziorizzontali(n);
				printf("---.__(___)\n");			
	
	  			spaziorizzontali(n-1);	  			
	  			printf("CARTA (+0) - |SCONFITTA| - FORBICE (+1)");	
	
			}
  			
  			break;
  			
 //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
						       //FORBICE//

    /*    _______
      ---'   ____)____
                ______)
             __________)
            (____)     
      ---.__(___)		*/
			       
 		case forbice:  //[Tasto 3]
  			
  			
  			if(*pG2==forbice)
  			{
				spaziorizzontali(n/2);			
	  			printf("    _______");  			spaziorizzontali(n);	
	  			printf("    _______\n");			spaziorizzontali(n/2);			  	
				printf("---'   ____)____");			spaziorizzontali(n-1);
				printf("---'   ____)____\n");		spaziorizzontali(n/2);					
				printf("          ______)"); 		spaziorizzontali(n-1);	
				printf("          ______)\n"); 		spaziorizzontali(n/2);					
				printf("      __________)");		spaziorizzontali(n-1);		
				printf("      __________)\n"); 		spaziorizzontali(n/2);				
				printf("      (____)");				spaziorizzontali(n);
				printf("      (____)\n");  			spaziorizzontali(n/2);						
				printf("---.__(___)"); 				spaziorizzontali(n);
				printf("---.__(___)\n");  	
				
	  			spaziorizzontali(n-1);	  			
	  			printf("FORBICE (+0) - |PAREGGIO| - FORBICE (+0)");						
							
			}
  		
  			else if (*pG2==carta)
			{
				P1++;					

				spaziorizzontali(n/2);			
	  			printf("    _______");  			spaziorizzontali(n);	
				printf("    _______\n"); 			spaziorizzontali(n/2);	  	  	
				printf("---'   ____)____");			spaziorizzontali(n-1);
				printf("---'   ____)____\n"); 		spaziorizzontali(n/2);			
				printf("          ______)"); 		spaziorizzontali(n-1);	
				printf("          ______)\n"); 		spaziorizzontali(n/2);				
				printf("      __________)"); 		spaziorizzontali(n-1);	
				printf("          _______)\n"); 	spaziorizzontali(n/2);				
				printf("      (____)");				spaziorizzontali(n);
				printf("         _______)\n"); 		spaziorizzontali(n/2);					
				printf("---.__(___)"); 			 	spaziorizzontali(n);
				printf("---.__________)\n");
				

	  			spaziorizzontali(n-1);	  			
	  			printf("FORBICE (+1) - |VITTORIA| - CARTA (+0)");	  			

			}
			
  			else if (*pG2==sasso)
			{
				P2++;
					
				spaziorizzontali(n/2);			
	  			printf("    _______");  		spaziorizzontali(n);	
				printf("    _______\n");   		spaziorizzontali(n/2);	
				printf("---'   ____)____");		spaziorizzontali(n-1);
				printf("---'   ____)\n");  		spaziorizzontali(n/2);				
				printf("          ______)"); 	spaziorizzontali(n-1);	
				printf("      (_____)\n"); 		spaziorizzontali(n/2);					
				printf("      __________)"); 	spaziorizzontali(n-1);	
				printf("      (_____)\n");  	spaziorizzontali(n/2);						
				printf("      (____)");			spaziorizzontali(n);
				printf("      (____)\n");    	spaziorizzontali(n/2);					
				printf("---.__(___)"); 			spaziorizzontali(n);			
				printf("---.__(___)\n");
			
	  			spaziorizzontali(n-1);	  			
	  			printf("FORBICE (+0) - |SCONFITTA| - SASSO (+1)");
				  				
			}
  			
  			break;
		}
		
		printf("\n");
	}
	
//**************************************************************************************************************************************************************/		
	
	//*********Tabella dei colori del prompt********//
	//												//												
	//* 0 = Nero       			8 = Grigio		    //
    //* 1 = Blu scuro        	9 = Blu			 	//	
    //* 2 = Verde       		A = Verde limone 	//
    //* 3 = Verde acqua         B = Azzurro			//
    //* 4 = Bordeaux         	C = Rosso			//	
    //* 5 = Viola      			D = Fucsia			//
    //* 6 = Verde oliva      	E = Giallo			//
    // *7 = Grigio chiaro       F = Bianco			//
    //												//
	//**********************************************//	

	void SETtheme(void)
	{
	
	   system("cls"); 
	  
	   enum temi
	   {
	   		classico=1,      
	   		chiaro,          
	   		scuro,         	 
	   		temi_speciali,
	   };
	   
	   enum temi_speciali
	   {
	   		alto_contrasto=1,  
	   		matrix,  
			limbo, 
			sweet_code,
			ender, 
			summer,
			mystical,
			inferno,
			playstation,   
			xbox,
			nintendo,			
	   		spiderman, 
			Dead_pool,   		   
	   		benevento,	
	   };
	   
	   int G1;						     		 											            									
	
	   do
	   {																							spaziverticali(1); spaziorizzontali(n);																		 	  	 									
	   printf("SELEZIONA IL TEMA");																	spaziverticali(2); spaziorizzontali(n-2);			 	  								  		
	   printf("Classico [1]  Chiaro [2]  Scuro [3]  Temi speciali [4]"); 		                    spaziverticali(2); spaziorizzontali(n-2);							   
	   	
	   scanf("%d",&G1);	
	   											     																						
	    if(G1<1||G1>5)
		{
	        do
	    	{	
				spaziverticali(2); spaziorizzontali(n-2);
				printf("DIGITAZIONE ERRATA, PREMI UN TASTO SEGUENDO LA LEGENDA: ");
				scanf("%d",&G1);
			}
	    	while(G1<1||G1>5);	//Verifica dell'input G1, controlla se minore di 1 o maggiore di 2, nel caso ripete il blocco di istruzioni.
		}
		
		switch (G1)
		{
			case classico:
			
			system("COLOR 07");
			
			break;

			case chiaro:
			
			system("COLOR f0");

			break;
			
			case scuro:
			
			system("COLOR 80");

			break;
			
			
			case temi_speciali:
			
			system("cls");																				spaziorizzontali(n);
			printf("SELEZIONA IL TEMA SPECIALE");														spaziverticali(2);
																										spaziorizzontali(n-2);						 	  								  		
	   		printf("Matrix [1] Alto contrasto [2] Limbo [3] Sweet Code [4] Ender [5]\n"); 				spaziorizzontali(n-2);
	   		printf("Summer [6] Mystical [7] Inferno [8] PlayStation [9] Xboxb [10]\n"); 				spaziorizzontali(n-2);
			printf("Nintendo [11] Spiderman [12] Dead Pool [13] Benevento [14]"); 						spaziverticali(2); spaziorizzontali(n-2);
		    scanf("%d",&G1);
		    								     																						
		    if(G1<1||G1>14)
			{
		        do
		    	{	
					spaziverticali(2); spaziorizzontali(n-2);
					printf("DIGITAZIONE ERRATA, PREMI UN TASTO SEGUENDO LA LEGENDA: ");
					scanf("%d",&G1);
				}
		    	while(G1<1||G1>14);	//Verifica dell'input G1, controlla se minore di 1 o maggiore di 2, nel caso ripete il blocco di istruzioni.		
			}
			
			switch(G1)
			{
			  	case alto_contrasto:
			    
			    system("COLOR 0A");
			    
			    break;
			    
			    
			    case matrix:
			    
			    system("COLOR 0f");
			    
			    break;
			    
		
			    case playstation:
			    
			    system("COLOR 1f");
			    
			    break;

			    
			    case xbox:
			    
			    system("COLOR 27");
			    
			    break;
			    
			    
			    case nintendo:
			    
			    system("COLOR 4f");
			    
			    break;

			
			    case spiderman:
			    
			    system("COLOR 41");
			    
			    break;
			    
			    
			    case sweet_code:
			    
			    system("COLOR B5");
			    
			    break;
			    
			    
			    case inferno:
			    
			    system("COLOR 42");
			    
			    break;
			    
			    
			    case limbo:
			    
			    system("COLOR 08");
			    
			    break;
			    
			    
			    case summer:
			    
			    system("COLOR E9");
			    
			    break;
			    
    
			    case mystical:
			    
			    system("COLOR 52");
			    
			    break;
			    
			    
			    			    
			    case ender:
			    
			    system("COLOR 05");
			    
			    break;
			    
			    
			    case Dead_pool:
			    
			    system("COLOR 04");
			    
			    break;
			    
			    
			    case benevento:
			    
			    system("COLOR 4E");
			    
			    break;
			    
			}
			
			 break;
		}
		  																	spaziverticali(2); spaziorizzontali(n-2);
		  printf("Conferma [1] Indietro [2]");								spaziverticali(2); spaziorizzontali(n-2);
		  scanf("%d",&G1); 
		  
		  if(G1<1||G1>2)
			{
		        do
		    	{	
					spaziverticali(2); spaziorizzontali(n-2);
					printf("DIGITAZIONE ERRATA, PREMI UN TASTO SEGUENDO LA LEGENDA: ");
					scanf("%d",&G1);
				}
		    	while(G1<1||G1>2);	//Verifica dell'input G1, controlla se minore di 1 o maggiore di 2, nel caso ripete il blocco di istruzioni.		
			}
		  
		  system("cls");
		}
		while(G1==2);
	}	

//**************************************************************************************************************************************************************/		

	void alfred (void)
	{
		setcolor(6);   
	    printf("\t\t\t _____         					   \n");     
	    printf("\t\t\t|     |		 					   \n");    
		printf("\t\t\t|");
		setcolor(8);   
		printf(" | |");
		setcolor(6);   
		printf(" |\n");
	    printf("\t\t\t|_____|\n");     
		printf("\t\t  ____ ___|_|___ ____   			   \n"); 
	    printf("\t\t ()___)         ()___)  			   \n");  
	    printf("\t\t // /|  ");   
	    setcolor(12);   
		printf("ALFRED");
		setcolor(6);   
		printf("\t |\\ \\\\\n");
	    printf("\t\t//  /|           |\\  \\\\  			\n");     
		printf("\t      (___)  |___________|  (___)			\n");     
	    printf("\t      (___)    (_______)    (___)			\n");     
		printf("\t      (___)      (___)      (___) 		\n"); 
		printf("\t      (___)       |_|       (___) 		\n");     
	    printf("\t      (___)   ___/___\\___    | |  		\n");     
	    printf("\t       | |   |  THL V.93 |   | |			\n");     
	    printf("\t       | |   |___________|  /___\\ 		\n");     
	    printf("\t      /___\\   |||     |||  //   \\\\   	\n");     
		printf("\t     //   \\\\  |||     |||  \\\\   //  	\n");     
		printf("\t     \\\\   //  |||     |||   \\\\ //   	\n");   
		printf("\t      \\\\ //  ()__)   (__()       		\n");   
		printf("\t             ///       \\\\\\            \n");   
		printf("\t            ///         \\\\\\    	   \n");  
		printf("\t          _///___     ___\\\\\\_         \n"); 
		printf("\t         |_______|   |_______|  	       \n");
		setcolor(6);
		printf("_________________________________________________\n\n");   			
	}

//**************************************************************************************************************************************************************/		

	void loading (void)	
	{
		int j, i;
		for(i=0;i<=2;i++)
		{	
			setcolor(i+1);
			
			gameboy();
		
			spaziverticali(1); spaziorizzontali(n);
			
			printf("      LOADING");
			
			j=0;
			while(j<3)
			{	
				sleep(1);
				printf(".");
				j++;
			}
		
			system("cls");
		}
	}
	
	void gameboy (void)
	{
		printf("\n"); spaziorizzontali(n);
		printf("_n_________________   	         	 \n");	spaziorizzontali(n);
		printf("|_|_______________|_|				 \n");	spaziorizzontali(n);
		printf("|  ,-------------.  |			     \n");	spaziorizzontali(n);
		printf("| |  .---------.  | |        	     \n");	spaziorizzontali(n);
		printf("| |  |         |  | |				 \n");	spaziorizzontali(n);
		printf("| |  |         |  | |          	     \n");	spaziorizzontali(n);
		printf("| |  |         |  | |				 \n");	spaziorizzontali(n);
		printf("| |  |         |  | |          	     \n");	spaziorizzontali(n);
		printf("| |  `---------'  | |				 \n");	spaziorizzontali(n);
		printf("| `---------------' |				 \n");	spaziorizzontali(n);
		printf("|   _The Last hand  |				 \n");	spaziorizzontali(n);
		printf("| _| |_         ,-. |				 \n");	spaziorizzontali(n);
		printf("||_ O _|   ,-. *._,*|				 \n");	spaziorizzontali(n);
		printf("|  |_|    *._,*   A |                \n");	spaziorizzontali(n);
		printf("|    _  _    B      | 			     \n");	spaziorizzontali(n);
		printf("|   // //           | 			     \n");	spaziorizzontali(n);
   		printf("|  // //       \\\\\\  |             \n");	spaziorizzontali(n);
		printf("|  `  `         \\\\\\ ,             \n");	spaziorizzontali(n);
		printf("|________...______,*				 \n");
	}	

//**************************************************************************************************************************************************************/		

	void rules (void)
	{
		gameboy();
			
		setcolor(6);
		printf("\n - The Last Hand ");
		
		setcolor(8);
		printf("simula la morra cinese, un gioco in cui lo scopo e' sconfiggere l'avversario scegliendo un segno in grado di battere quello dell'altro, secondo le seguenti regole:");
		
		printf("\n\n * Il sasso spezza le forbici (vince il sasso)\n * Le forbici tagliano la carta (vincono le forbici)\n * La carta avvolge il sasso (vince la carta)\n\n");  
		
		printf("\n - Comandi:\n");
		
		setcolor(8); rock();  
		
		setcolor(15); paper();  
		
		setcolor(4); scissors();	
		
		setcolor(6);
		printf("\n\n- Premi un tasto per inziare a giocare");
		
		fflush(stdin); getchar();
		
		system("cls");
	}
		
//**************************************************************************************************************************************************************/		

	void rock (void)
	{
			printf("\t          _______ 							\n");	
			printf("\t      ---'   ____) 							\n");		
			printf("\t            (_____) 							\n");		
			printf("\t Tasto [1]  (_____) Sasso							\n");		
			printf("\t            (____) 							\n");		
			printf("\t      ---.__(___) 							\n");		
	}	
	
//**************************************************************************************************************************************************************/		
	
	void paper (void)
	{
			printf("\t          _______          		 			\n");		
			printf("\t      ---'   ____)____          		 		\n");		
			printf("\t                ______)          		 		\n");		
			printf("\t Tasto [2]      _______) Carta          		\n");		
			printf("\t               _______)          		 		\n");		
			printf("\t      ---.__________)          		 		\n");		
					
	}	

//**************************************************************************************************************************************************************/		

	 void scissors (void)
	{			
			printf("\t          _______          		 			\n");		
			printf("\t      ---'   ____)____          		 		\n");		
			printf("\t                ______)          		 		\n");		
			printf("\t Tasto [3]   __________) Forbice          	\n");		
			printf("\t            (____)          		 			\n");		
			printf("\t      ---.__(___)          		 			\n");			
	}
	
//**************************************************************************************************************************************************************/														     										   	
