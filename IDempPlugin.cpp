#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "IDempPlugin.h"

void IDempPlugin::input(std::string file) {
   readParameterFile(file);
}

void IDempPlugin::run() {}

void IDempPlugin::output(std::string file) {
//aqmm  -a AS_metagenome -b AS_metatranscriptome -m meta_data.txt -n 12 -o testout2
//../IDempMain/IDemp -p1 1a21A.pdb -p2 1hwgC.pdb -o 1a21A_1hwgC -m -ac -t
       	std::string outputfile = file;
 std::string myCommand = "idemp -b "+PluginManager::addPrefix(myParameters["barcode"])+" -I1 "+PluginManager::addPrefix(myParameters["bfastq"])+" -R1 "+PluginManager::addPrefix(myParameters["r1fastq"])+" -R2 "+PluginManager::addPrefix(myParameters["r2fastq"])+" -m -n -o "+file;
 std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<IDempPlugin> IDempPluginProxy = PluginProxy<IDempPlugin>("IDemp", PluginManager::getInstance());
