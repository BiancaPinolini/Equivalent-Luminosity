void eqlumi(char const *MC_prod, char const *MC_step, char const *sample_name, Int_t N_samples, Int_t sample_year) {
        
        // Count the number of generated events
    Double_t Sum = 0;
    Double_t N;
    std::cout << sample_name << std::endl;

    char str[200];

    for(Int_t i = 0; i <= N_samples; i++){

        char buffer[N_samples-1];
        sprintf(buffer, "%d", i);

        strcpy (str, "/eos/cms/store/group/phys_higgs/cmshww/amassiro/HWWNano");
        strcat (str, MC_prod);
        strcat (str, MC_step);
        strcat (str, "/nanoLatino_");
        strcat (str, sample_name);
        strcat (str, "__part");
	    strcat (str, buffer);
        strcat (str,".root");

        TFile *f = new TFile(str, "READ");
        TTree *T = (TTree*)f->Get("Runs");

        if(sample_year == 2018) T->SetBranchAddress("genEventSumw_",&N);
        else T->SetBranchAddress("genEventSumw",&N);        
        T->GetEntry(0);
	Sum += N;

    }
    std::cout << "Number of events = " << Sum << std::endl;

        // Extract the cross section
    
    TFile *f_events = new TFile(str, "READ");
    TTree *T_events = (TTree*)f_events->Get("Events");
    Float_t xsec;
    T_events->SetBranchAddress("Xsec",&xsec);
    T_events->GetEntry(0);
    std::cout << "Xsec (pb) = " << xsec << std::endl;

    std::cout << "Equivalent Luminosity (/pb) = " << Sum/xsec << std::endl;

}
