#include "diphotonreso.C"
#include "diphotonreso.h"
#include "TROOT.h"
 
int main(){                                                                                                                                                                        
  //gROOT->ProcessLine("#include <vector>");
  //gROOT->ProcessLine("#include <map>");
  //gROOT->ProcessLineSync(".x RooDoubleSidedCB.cxx+");
  gROOT->ProcessLineSync(".x RooDCBShape.cxx+");
  gSystem->Load("libDCache.so");
  gSystem->Load("libRooFit.so");
  gSystem->SetIncludePath( "-I$ROOFITSYS/include/" );
  gSystem->Load("libRooFitCore.so") ;
  diphotonreso m;
  m.Loop();
 
}
