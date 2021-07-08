// compile: g++ -g -O2 -std=c++11 -pthread -march=native RSA.cpp RSAFun.cpp -o RSA -lntl -lgmp -lm
#include <iostream>
#include <NTL/ZZ.h>
#include "RSA.h"

using namespace std;
using namespace NTL;
int main(){
    
    cout <<"\n         ____  ____    _    \n";
    cout <<"        |  _ \\/ ___|  / \\   \n";
    cout <<"        | |_) \\___ \\ / _ \\  \n";
    cout <<"        |  _ < ___) / ___ \\ \n";
    cout <<"        |_| \\_\\____/_/   \\_\\ \n\n\n";
    int select = 0;
    cout << "1) Muestra\n";
    cout << "2) Enviar mensaje\n";
    cout << "3) Recibir mensaje\n";
    cout << "Seleccione: ";
    cin >> select;
    
    if (select == 1){

        int bits = 0;
        cout << "Ingrese la cantidad de bits: "; cin >> bits;
        cin.ignore();
        RSA receptor(bits);

        RSA emisor(bits);

        // examples:
        // "vis an alii graeci ne magna elitr ubique per mei te quis reque epicuri libris deleniti appareat vel et at tale labores urbanitas sit duo eu noster epicurei consetetur sea sumo principes adversarium an prima audire apeirian ut usu nonumy complectitur vix ad id duo vero etiam adversarium et aliquam scaevola adipiscing vis nam at case salutatus contentiones decore facilis appareat eu qui ne omnesque consequuntur vim eos an amet vocent mei ei feugait salutandi mel novum causae in pro id duis dolore incorrupte option equidem sed no vis nullam menandri ullamcorper at nullam vocent splendide ut vel"
        // "el unico sistema completamente seguro es aquel que esta apagado encerrado en un bloque de cemento y sellado en una habitacion rodeada de alambradas y guardias armados"
        receptor.establecer(emisor.getE(), emisor.getN());
        emisor.establecer(receptor.getE(), receptor.getN());
        string mensaje = "el unico sistema completamente seguro es aquel que esta apagado encerrado en un bloque de cemento y sellado en una habitacion rodeada de alambradas y guardias armados";

        string mensajeCifrado = emisor.cifrar(mensaje);
    
        cout << "\nMensaje cifrado\n";

        cout << "Emisor: " << mensajeCifrado << endl;
    
        cout << "\nMensaje descifrado\n";
        string mensajeDescifrado = receptor.descifrar(mensajeCifrado);

        cout << "Receptor: " << "'" << mensajeDescifrado <<"'"<< endl;
    
    }   
    else if(select == 2)
    {
        int bits = 0;
        cout << "Ingrese la cantidad de bits: "; cin >> bits;

        ZZ e, N;
        cout << "Receptor e: ";cin >> e;
        cout << "Receptor N: ";cin >> N;

        cin.ignore();
        RSA emisor(bits);
        emisor.establecer(e, N);
        string mensaje;
        getline(cin, mensaje);
        string mensajeCifrado = emisor.cifrar(mensaje);
        
        cout << "Mensaje cifrado: " << mensaje << endl;
        cout << "Emisor: " << mensajeCifrado << endl;

    }
    else if(select == 3)
    {
        
        int bits = 0;
        cout << "Ingrese la cantidad de bits\n"; cin >> bits;
    
        RSA receptor(bits);
        cout << "e: " << receptor.getE() << endl;
        cout << "n: " << receptor.getN() << endl;

        ZZ e, N;
        cout << "Emisor e:";cin >> e;
        cout << "Emisor N: ";cin >> N;
        receptor.establecer(e, N);

        cin.ignore();
        string mensaje;
        cout << "Mensaje cifrado: ";
        getline(cin, mensaje);

        cout << "Mensaje descifrado: " <<receptor.descifrar(mensaje) << endl;
    }

    // ZZ p, q, e, d;
    // // cout << "p: ";
    // // cin >>p;
    // // cout << "q: ";
    // // cin >>q;
    // // cout << "e: ";
    // // cin >>e;
    // // cout << "d: ";
    // // cin >>d;
    // p = conv<ZZ>("154094845570608329244966631943657424988439146164810466685246837819684977755667016681320388705890945713897689084846266360790476421910349906754958317241576483319619059781860384893887075155557610125048573447294859154768251676146238176327576949477213016447428592859161284383785030447221785927790868405550701925987");
    // q = conv<ZZ>("128806997512276380317742296866215616844564248861112407754948608397347288620856451888818193478510413516777019353847348214484716564144014289518157725737524524585222132654839961842249764352034728838246720346430597647739158047868530257931480892296340559785257747808731348570204867482458486671397220530726596121181");
    // e = conv<ZZ>("125785490430896920479115795429775514149851932216997344242679273584202881615657523588016698045293432423714800316700353368431454560307574449611123443193837599044715201391536033640958331085066725474076480680823223810304692493174491487847247423800246008713627131777107618098848820568724081440767484666511189855127");
    // d = conv<ZZ>("548270001696161514146033910192230924228886653642375213994639481610864817702403995950812614899487586750910567102381360876421398257607337007696211991807139988301211254033232901613605005574747738106077567113281154402175112378780618188522692516376828830757359038573689538114492834265600163760424089405058708840354901445282326653735706718910864204325170362639906591100987114589339481487680394356595034055272116302884161491673596204895352468063927349622758933096742467472751115112457591432155527854531189800347115766196227179001484018549384258437636689588928152876863103254295803022636671722865559862196944707866997460743");
    // RSA emisor(p,q,e,d);
    // ZZ eR, nR;
    // eR = conv<ZZ>("135066410865995223349603216278805969938881475605667027524485143851526510604859533833940287150571909441798207282164471551373680419703964191743046496589274256239341020864383202110372958725762358509643110564073501508187510676594629205563685529475213500852879416377328533906109750544334999811150056977236890927563");
    // nR = conv<ZZ>("25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784406918290641249515082189298559149176184502808489120072844992687392807287776735971418347270261896375014971824691165077613379859095700097330459748808428401797429100642458691817195118746121515172654632282216869987549182422433637259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133844143603833904414952634432190114657544454178424020924616515723350778707749817125772467962926386356373289912154831438167899885040445364023527381951378636564391212010397122822120720357");
    // // cout << "er: "; cin >> eR;
    // // cout << "nR: "; cin >> nR;
    // emisor.establecer(eR, nR);

    // cin.ignore();
    // string mensaje;
    // cout << "mensaje: ";
    // getline(cin, mensaje);
    // cout << "cifrado: " << emisor.cifrar(mensaje) << endl;
    // cout << "firma: " << emisor.firma_digital_cifrado(emisor.leer_datos("firma.txt")) << endl;

}