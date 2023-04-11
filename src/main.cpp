/*
 * Metodología de la Programación: Language2
 * Curso 2022/2023
 */

/* 
 * File:   main.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 *
 * Created on 7 de febrero de 2023, 14:02
 */

using namespace std;
#include <fstream>
#include "Language.h"
/**
 * Shows help about the use of this program in the given output stream
 * @param outputStream The output stream where the help will be shown (for example,
 * cout, cerr, etc) 
 */
void showEnglishHelp(ostream& outputStream) {
    outputStream << "Error, run with the following parameters:" << endl;
    outputStream << "language2 <file1.bgr> [<file2.bgr> ... <filen.bgr>] <outputFile.bgr> " << endl;
}

/**
 * This program reads an undefined number of Language objects from the files
 * passed as parameters to main(). It obtains as result the union of all the 
 * input Language objects. The result is then sorted by decreasing order of 
 * frequency and alphabetical order of bigrams when there is any tie in 
 * frequencies. Finally the resulting Language is saved in an output file. The 
 * program must have at least an input file and an output file. 
 * The output Language will have as language identifier, the one of the first
 * file (<file1.bgr>). If an input file <file*.bgr> has a language identifier
 * different from the one of the first file (<file1.bgr>), then it will not
 * be included in the union.
 * Running example:
 * > language2 <file1.bgr> [<file2.bgr> ... <filen.bgr>] <outputFile.bgr> 
 */
int main(int argc, char* argv[]) {
    
    // Para terminar la ejecución del programa en caso de no tener al menos un archivo de entrada y otro de salida
    if(argc < 3){
        exit(1);
    }
    string output_file_name;
    Language l_final;
    for(int i = 1; i < argc; i++){
        std::string arg(argv[i]);
        output_file_name += arg + " ";
        
        cout << argv[i] << " PROCESADO " << endl;
        Language l_aux(50);
        
        l_aux.load(argv[i]);
        
        l_final.join(l_aux);
    }
    cout << "Nombre del fichero de salida: " << output_file_name << endl;
    l_final.sort();
    cout << l_final.getLanguageId() << endl;
    cout << l_final.toString();
    
    
    // argc - 1 = output language
    
    
//    Language l(3);
//    Language l1(3);
//    l.setLanguageId("Spanish");
//    BigramFreq bf;
//    Bigram b1("aa");
//    bf.setBigram(b1);
//    bf.setFrequency(7);
//    
//    l.at(1) = bf;
//    
//    //cout << l.findBigram(b1);
//    cout << l1.toString() << endl ;
//    
//    l.sort();
//    
//    l1.load("index.txt");
//    
//    BigramFreq bf1;
//    Bigram b2("bb");
//    bf1.setBigram(b2);
//    bf1.setFrequency(3);
//     BigramFreq bf2;
//    Bigram b3("ee");
//    bf2.setBigram(b3);
//    bf2.setFrequency(3);
//     BigramFreq bf3;
//    Bigram b4("uu");
//    bf3.setBigram(b4);
//    bf3.setFrequency(3);
//    
//    l1.append(bf1);
//    l1.append(bf2);
//    l1.append(bf3);
//    
//    l.join(l1);
//    l.save("index.txt");
//    
//    cout << l.toString();
//    
//    //cout << l.at(0).toString();
//    
//    Bigram b("__");
//    //
}

