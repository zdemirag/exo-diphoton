void read(){

    TFile *file_mc = new TFile("histograms_diphoton_tree_MC_all.root","READ");
    TH1F *h_mc = (TH1F*)file_mc->Get("h_Diphoton_Minv_FineBinning");

    TFile *file_jj = new TFile("histograms_ExoDiPhotonAnalyzer_LooseDataABCD2012_JetJet.root","READ");
    TH1F *h_jj = (TH1F*)file_jj->Get("h_JetJet_minv_FineBinning");

    TFile *file_gj = new TFile("histograms_ExoDiPhotonAnalyzer_LooseDataABCD2012_GammaJet.root","READ");
    TH1F *h_gj = (TH1F*)file_gj->Get("h_GammaJet_minv_FineBinning");

    std::cout << "h_mc->Integral(): " << h_mc->Integral() << std::endl; 
    h_mc->Scale(19376);    
    std::cout << "h_mc->Integral(): " << h_mc->Integral() << std::endl; 
    h_mc->Add(h_jj);
    std::cout << "h_jj->Integral(): " << h_jj->Integral() << std::endl; 
    h_mc->Add(h_gj);
    std::cout << "h_gj->Integral(): " << h_gj->Integral() << std::endl; 
    //h_mc->Draw();
    std::cout << "h_mc->Integral(): " << h_mc->Integral() << std::endl;

/*
    TFile *filenew = new TFile("zeynep.root","RECREATE");
    TTree *tree = new TTree("T","An example of a ROOT tree");
    float mass;

    tree->Branch("mass", &mass,"mass/F");

    for(int i = 0; i<h_mc->GetNbinsX(); i++){
        std::cout << "Bin: " << i << " GetBinContent: " << h_mc->GetBinContent(i) << std::endl;        
        //mass = h_mc->GetBinLowEdge(i);
        for(float j = 0; j < h_mc->GetBinContent(i); j+0.00001 ){            
            //std::cout << "GetBinCenter: " << h_mc->GetBinLowEdge(j)<< " Get Bin Center2: " << h_mc->GetBinCenter(i) <<" BinContent: " << h_mc->GetBinContent(i) << std::endl;
            mass = h_mc->GetBinLowEdge(i);
            std::cout << "Bin: " << i << " mass: " << mass << std::endl;
            tree->Fill();
        }
    }
*/
    h_mc->Draw();
    //  tree->Write();
    
}
