# Equivalent-Luminosity
This ROOT macro extracts the number of generated events, the Cross Section and computes the integrated equivalent luminosity from the Latinos samples.

All you need to know is:
1. mcProduction 
2. mcSteps 
3. Sample name 
4. Number of samples
5. Data-taking year

Then you must run:
root 'eqlumi.C(mcProduction, mcSteps, Sample name, Number of samples, Data-taking year)'

For example, if you want to know the integrated equivalent luminosity of the sample TTTo2L2Nu, from the 2018 data-taking period and for which:
mcProduction = "/Autumn18_102X_nAODv6_Full2018v6"
mcSteps = "/MCl1loose2018v6__MCCorr2018v6__l2loose__l2tightOR2018v6"
And you know (looking into the repository) that there are 58 TTTo2L2Nu samples, you must run:

root 'eqlumi.C("/Autumn18_102X_nAODv6_Full2018v6", "/MCl1loose2018v6__MCCorr2018v6__l2loose__l2tightOR2018v6", "TTTo2L2Nu", 58, 2018)'

Pay attention!
a. In both mcProduction and mcSteps you must insert a "/" at the beginning
b. The number of samples and the data-taking years are to be entered as Int numbers
