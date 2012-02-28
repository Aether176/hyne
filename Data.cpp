/****************************************************************************
 ** Hyne Final Fantasy VIII Save Editor
 ** Copyright (C) 2009-2012 Arzel J�r�me <myst6re@gmail.com>
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/
/****************************************************************************
 ** Part of this code was written by Qhimm in its Griever program.
 ** Source code available at http://qhimm.com/
 ****************************************************************************/

#include "Data.h"

QString Data::currentPath = QString();
QStringList Data::abilities;
QStringList Data::magic;
QStringList Data::items;
QStringList Data::locations;
QStringList Data::weapons;
QStringList Data::names;
QStringList Data::gfnames;
QStringList Data::cards;
QStringList Data::zellLB;
QStringList Data::irvineLB;
QStringList Data::quistisLB;
QStringList Data::rinoaLB;
QStringList Data::ennemies;

void Data::load()
{
	if(!abilities.isEmpty()) {
		abilities.clear();
		magic.clear();
		items.clear();
		locations.clear();
		weapons.clear();
		names.clear();
		gfnames.clear();
		zellLB.clear();
		irvineLB.clear();
		quistisLB.clear();
		rinoaLB.clear();
		ennemies.clear();
	}

	abilities << QString("") << QObject::tr("HP-A") << QObject::tr("Vgr-A") << QObject::tr("Dfs-A") << QObject::tr("Mgi-A") << QObject::tr("Psy-A")
			<< QObject::tr("Vts-A") << QObject::tr("Esq-A") << QObject::tr("Prc-A") << QObject::tr("Chc-A") << QObject::tr("Atq-�l�-A")
			<< QObject::tr("Atq-Mtl-A") << QObject::tr("D�f-�l�-A") << QObject::tr("D�f-Mtl-A") << QObject::tr("D�f-�l�X2") << QObject::tr("D�f-�l�X4")
			<< QObject::tr("D�f-Mtl-Ax2") << QObject::tr("D�f-Mtl-Ax4") << QObject::tr("Capacit�X3") << QObject::tr("Capacit�X4") << QObject::tr("Magie")
			<< QObject::tr("G-Force") << QObject::tr("Voler") << QObject::tr("Objets") << "???" << QObject::tr("Carte")
			<< QObject::tr("Ch�timent") << QObject::tr("Mad Rush") << QObject::tr("Traitement") << QObject::tr("D�fense") << QObject::tr("Combustion")
			<< QObject::tr("Arnica") << QObject::tr("Phagocyte") << QObject::tr("Ranimer") << QObject::tr("Nv Moins") << QObject::tr("Nv Plus")
			<< QObject::tr("Kamikaze") << QObject::tr("Cannibale") << QObject::tr("Mini Kikou") << QObject::tr("HP+20%") << QObject::tr("HP+40%")
			<< QObject::tr("HP+80%") << QObject::tr("Vgr+20%") << QObject::tr("Vgr+40%") << QObject::tr("Vgr+60%") << QObject::tr("Dfs+20%")
			<< QObject::tr("Dfs+40%") << QObject::tr("Dfs+60%") << QObject::tr("Mgi+20%") << QObject::tr("Mgi+40%") << QObject::tr("Mgi+60%")
			<< QObject::tr("Psy+20%") << QObject::tr("Psy+40%") << QObject::tr("Psy+60%") << QObject::tr("Vit+20%") << QObject::tr("Vit+40%")
			<< QObject::tr("Esq+30%") << QObject::tr("Chc+50%") << QObject::tr("Piller") << QObject::tr("Schweitzer") << QObject::tr("Amorce")
			<< QObject::tr("Backlash") << QObject::tr("Empathie") << QObject::tr("Genki") << QObject::tr("Atlas-HP") << QObject::tr("Bonus HP","ability")
			<< QObject::tr("Bonus Vgr","ability") << QObject::tr("Bonus Dfs","ability") << QObject::tr("Bonus Mgi","ability") << QObject::tr("Bonus Psy","ability") << QObject::tr("Auto-Carapace")
			<< QObject::tr("Auto-Blindage") << QObject::tr("Auto-Boomerang") << QObject::tr("Auto-Booster") << QObject::tr("Auto-Potion") << QObject::tr("DoublEco")
			<< QObject::tr("TriplEco") << QObject::tr("Freud", "ability") << QObject::tr("Prudence") << QObject::tr("Clairvoyance") << QObject::tr("Mi-Combat")
			<< QObject::tr("No-Combat") << QObject::tr("Sensor") << QObject::tr("Invoc+10%") << QObject::tr("Invoc+20%") << QObject::tr("Invoc+30%")
			<< QObject::tr("Invoc+40%") << QObject::tr("HP-GF+10%") << QObject::tr("HP-GF+20%") << QObject::tr("HP-GF+30%") << QObject::tr("HP-GF+40%")
			<< QObject::tr("Turbo") << QObject::tr("Souk") << QObject::tr("Sentier") << QObject::tr("Connaisseur") << QObject::tr("Boutiques")
			<< QObject::tr("Bazars") << QObject::tr("Cr�a-Mgi-C�l") << QObject::tr("Cr�a-Mgi-Gla") << QObject::tr("Cr�a-Mgi-Inc") << QObject::tr("Cr�a-Mgi-M�d")
			<< QObject::tr("Cr�a-Mgi-Temp") << QObject::tr("Cr�a-Mgi-Mtl") << QObject::tr("Cr�a-Mgi-Pro") << QObject::tr("Cr�a-Mgi-Tab") << QObject::tr("Cr�a-Mgi-Th�r")
			<< QObject::tr("Cr�a-Mgi-Ana") << QObject::tr("Cr�a-Balles") << QObject::tr("Cr�a-Outils") << QObject::tr("Cr�a-Th�r-Tab") << QObject::tr("Cr�a-Th�r-GF")
			<< QObject::tr("Cr�a-Capa-GF") << QObject::tr("Cr�a-Mgi-Plus") << QObject::tr("Cr�a-Mgi-Max") << QObject::tr("Soins NV +") << QObject::tr("Mode Carte");
	
	magic << QString("-") << QObject::tr("Brasier") << QObject::tr("Brasier+") << QObject::tr("BrasierX") << QObject::tr("Glacier") << QObject::tr("Glacier+")
			<< QObject::tr("GlacierX") << QObject::tr("Foudre") << QObject::tr("Foudre+") << QObject::tr("FoudreX") << QObject::tr("H2o") << QObject::tr("Rafale") << QObject::tr("Cyanure")
			<< QObject::tr("Quart") << QObject::tr("Sid�ral") << QObject::tr("Fournaise") << QObject::tr("M�t�ore") << QObject::tr("Quake") << QObject::tr("Tornade") << QObject::tr("Ultima")
			<< QObject::tr("Apocalypse") << QObject::tr("Soin") << QObject::tr("Soin +") << QObject::tr("Soin Max") << QObject::tr("Vie") << QObject::tr("Vie Max") << QObject::tr("R�cup") << QObject::tr("Esuna")
			<< QObject::tr("Anti-sort") << QObject::tr("Carapace") << QObject::tr("Blindage") << QObject::tr("Boomrg") << QObject::tr("Aura") << QObject::tr("Double") << QObject::tr("Triple") << QObject::tr("Booster")
			<< QObject::tr("Somni") << QObject::tr("Stop") << QObject::tr("C�cit�") << QObject::tr("Folie") << QObject::tr("Morph�e") << QObject::tr("Aphasie") << QObject::tr("M�galith") << QObject::tr("Ankou")
			<< QObject::tr("Saign�e") << QObject::tr("Supplice") << QObject::tr("Furie") << QObject::tr("D�cubitus") << QObject::tr("Zombie") << QObject::tr("Meltdown") << QObject::tr("Scan") << QObject::tr("Joobu")
			<< QObject::tr("Wall") << QObject::tr("Arkange") << QObject::tr("Percent") << QObject::tr("Catastrophe") << QObject::tr("The End");
	
	items << "" << QObject::tr("Potion") << QObject::tr("Potion+") << QObject::tr("Hypra-Potion") << QObject::tr("Maxi potion") << QObject::tr("Potion totale")
			<< QObject::tr("M�ga potion") << QObject::tr("MT-Psy") << QObject::tr("Maxi MT-Psy") << QObject::tr("Elixir") << QObject::tr("M�galixir") << QObject::tr("Antidote")
			<< QObject::tr("D�fijeur") << QObject::tr("Lasik") << QObject::tr("Bocca") << QObject::tr("Eau b�nite") << QObject::tr("Rem�de") << QObject::tr("Rem�de +")
			<< QObject::tr("1-20-Syble") << QObject::tr("Invuln�rable") << QObject::tr("1-destructible") << QObject::tr("Croisade") << QObject::tr("Roc cosse")
			<< QObject::tr("Roc carapace") << QObject::tr("Roc d'Aura") << QObject::tr("Roc mortel") << QObject::tr("Roc sacr�") << QObject::tr("Roc flamboyant")
			<< QObject::tr("Roc M�t�ore") << QObject::tr("Roc Ultima") << QObject::tr("ChocoL�gume") << QObject::tr("Golgotha","item") << QObject::tr("Pen Pal")
			<< QObject::tr("Red Kross") << QObject::tr("Zoologie") << QObject::tr("Saindoux") << QObject::tr("Potion GF") << QObject::tr("Potion GF +")
			<< QObject::tr("M�gapotion GF") << QObject::tr("Sel marin") << QObject::tr("Carte bapt�me") << QObject::tr("D�capaciteur") << QObject::tr("Livret HP-A")
			<< QObject::tr("Livret Vgr-A") << QObject::tr("Livret Dfs-A") << QObject::tr("Livret Mgi-A") << QObject::tr("Livret Psy-A") << QObject::tr("Livret Vts-A")
			<< QObject::tr("Livret Chc-A") << QObject::tr("Shadow") << QObject::tr("Assaut El�") << QObject::tr("Antichoc El�") << QObject::tr("Assaut Mtl")
			<< QObject::tr("Antichoc Mtl") << QObject::tr("Roc Rosette") << QObject::tr("GrimoMagic") << QObject::tr("GrimoForce") << QObject::tr("GrimoVole")
			<< QObject::tr("GrimObjets") << QObject::tr("Vegas Feel") << QObject::tr("Sanatorium") << QObject::tr("M�temPsy") << QObject::tr("Bandage") << QObject::tr("Nova")
			<< QObject::tr("R�gime") << QObject::tr("Kikkou Mania") << QObject::tr("Sam�dhi") << QObject::tr("Zodiaque") << QObject::tr("Nuclide") << QObject::tr("Sacrum")
			<< QObject::tr("Billet") << QObject::tr("Vierge", "item1") << QObject::tr("Armure d'or") << QObject::tr("Cuirasse") << QObject::tr("Anneau R�cup") << QObject::tr("Alliance")
			<< QObject::tr("Bague Ga�a") << QObject::tr("Vitamine") << QObject::tr("Sagou") << QObject::tr("Sagette") << QObject::tr("Coquille") << QObject::tr("Halcyon")
			<< QObject::tr("Adamantine") << QObject::tr("Obole") << QObject::tr("Tao") << QObject::tr("Lacan") << QObject::tr("Garcinord") << QObject::tr("Merlin")
			<< QObject::tr("Magax") << QObject::tr("Injection") << QObject::tr("SuperSonic") << QObject::tr("Pied de biche") << QObject::tr("Ecaille") << QObject::tr("Tasmania")
			<< QObject::tr("Speedy") << QObject::tr("R�actor") << QObject::tr("Protector") << QObject::tr("Pasteur") << QObject::tr("Manivelle") << QObject::tr("Trilogie")
			<< QObject::tr("Freud", "item") << QObject::tr("Balles normales") << QObject::tr("Mitra-balles") << QObject::tr("Dark balles") << QObject::tr("Balles foudre")
			<< QObject::tr("Balles tornade") << QObject::tr("Balles v�loces") << QObject::tr("Balles anti-char") << QObject::tr("Balles Pulsar") << QObject::tr("Caillou magik")
			<< QObject::tr("Roc initiatique") << QObject::tr("Roc f�erique") << QObject::tr("Tentacule") << QObject::tr("Onde b�nite") << QObject::tr("Plumage")
			<< QObject::tr("Poudre Zombie") << QObject::tr("Bottes de 7km") << QObject::tr("9 inch nail") << QObject::tr("Enclume") << QObject::tr("Cimeterre")
			<< QObject::tr("Corne") << QObject::tr("Sanguine") << QObject::tr("EuFurysant") << QObject::tr("Ep�e trompeuse") << QObject::tr("Poudre Morph�e")
			<< QObject::tr("Anneau de vie") << QObject::tr("Lochness") << QObject::tr("U-Boat") << QObject::tr("Etoile") << QObject::tr("Weirdo") << QObject::tr("Gen-X")
			<< QObject::tr("Fluide") << QObject::tr("M-Double") << QObject::tr("House") << QObject::tr("Chevrotine") << QObject::tr("Canicule") << QObject::tr("Germe")
			<< QObject::tr("Rh�ne") << QObject::tr("Rayon") << QObject::tr("Vierge", "item2") << QObject::tr("V-Choc") << QObject::tr("H-Espace") << QObject::tr("Hot Rock")
			<< QObject::tr("Molaire") << QObject::tr("Blizzard") << QObject::tr("Nunatak") << QObject::tr("Gemma Luce") << QObject::tr("Aigrette") << QObject::tr("Canine")
			<< QObject::tr("Globe d'acier") << QObject::tr("Roc lunaire") << QObject::tr("F�mur") << QObject::tr("Aquilon") << QObject::tr("Derme") << QObject::tr("Zyg�ne")
			<< QObject::tr("Shark") << QObject::tr("Poudre Aphasie") << QObject::tr("Venin") << QObject::tr("Revenant") << QObject::tr("D�sosseur ") << QObject::tr("Kaktos")
			<< QObject::tr("Roc Shaman") << QObject::tr("Essence") << QObject::tr("Comtesse Cochon") << QObject::tr("Missive d'Edea") << QObject::tr("Collier Chocobo")
			<< QObject::tr("Collier chien") << QObject::tr("Bague du chef") << QObject::tr("Aladore") << QObject::tr("Bonus Hp","item") << QObject::tr("Bonus Vgr","item")
			<< QObject::tr("Bonus Dfs","item") << QObject::tr("Bonus Mgi","item") << QObject::tr("Bonus Psy","item") << QObject::tr("Bonus Vts","item") << QObject::tr("Bonus Chc","item")
			<< QObject::tr("Amour bestial") << QObject::tr("F.F.F. F�v") << QObject::tr("F.F.F. Mar") << QObject::tr("F.F.F. Avr") << QObject::tr("F.F.F. Mai")
			<< QObject::tr("F.F.F. Jun") << QObject::tr("F.F.F. Jul") << QObject::tr("F.F.F. Ao�") << QObject::tr("Baston mag 1") << QObject::tr("Baston mag 2")
			<< QObject::tr("Baston mag 3") << QObject::tr("Baston mag 4") << QObject::tr("Baston mag 5") << QObject::tr("L'A D b�tes 1") << QObject::tr("L'A D b�tes 2")
			<< QObject::tr("L'A D b�tes 3") << QObject::tr("L'A D b�tes 4") << QObject::tr("L'A D b�tes 5") << QObject::tr("L'A D b�tes 6") << QObject::tr("Occult Fan I")
			<< QObject::tr("Occult Fan II") << QObject::tr("Occult Fan III") << QObject::tr("Occult Fan IV");

	locations << QString("???") << QObject::tr("Plaines d'Arkland - Balamb","1") << QObject::tr("Monts Gaulg - Balamb","2") << QObject::tr("Baie de Rinaul - Balamb","3") << QObject::tr("Cap Raha - Balamb","4") << QObject::tr("For�t de Rosfall - Timber","5") << QObject::tr("Mandy Beach - Timber","6") << QObject::tr("Lac Obel - Timber","7") << QObject::tr("Vall�e de Lanker - Timber","8") << QObject::tr("Ile Nantakhet - Timber","9") << QObject::tr("Yaulny Canyon - Timber","10") << QObject::tr("Val Hasberry - Dollet","11") << QObject::tr("Cap Holy Glory - Dollet","12") << QObject::tr("Longhorn Island - Dollet","13") << QObject::tr("P�ninsule Malgo - Dollet","14") << QObject::tr("Plateau Monterosa - Galbadia","15")
			<< QObject::tr("Lallapalooza Canyon - Galbadia","16") << QObject::tr("Shenand Hill - Timber","17") << QObject::tr("P�ninsule Gotland - Galbadia","18") << QObject::tr("Ile de l'Enfer - Galbadia","19") << QObject::tr("Plaine Galbadienne","20") << QObject::tr("Wilburn Hill - Galbadia","21") << QObject::tr("Archipel Rem - Galbadia","22") << QObject::tr("Dingo D�sert - Galbadia","23") << QObject::tr("Cap Winhill","24") << QObject::tr("Archipel Humphrey - Winhill","25") << QObject::tr("Ile Winter - Trabia","26") << QObject::tr("Val de Solvard - Trabia","27") << QObject::tr("Cr�te d'Eldbeak - Trabia","28") << QString("") << QObject::tr("Plaine d'Hawkind - Trabia","30") << QObject::tr("Atoll Albatross - Trabia","31")
			<< QObject::tr("Vallon de Bika - Trabia","32") << QObject::tr("P�ninsule Thor - Trabia","33") << QString("") << QObject::tr("Cr�te d'Heath - Trabia","35") << QObject::tr("Trabia Crater - Trabia","36") << QObject::tr("Mont Vienne - Trabia","37") << QObject::tr("Plaine de Mordor - Esthar","38") << QObject::tr("Mont Nortes - Esthar","39") << QObject::tr("Atoll Fulcura - Esthar","40") << QObject::tr("For�t Grandidi - Esthar","41") << QObject::tr("Iles Millefeuilles - Esthar","42") << QObject::tr("Grandes plaines d'Esthar","43") << QObject::tr("Esthar City","44") << QObject::tr("Salt Lake - Esthar","45") << QObject::tr("C�te Ouest - Esthar","46") << QObject::tr("Mont Sollet - Esthar","47")
			<< QObject::tr("Vall�e d'Abadan - Esthar","48") << QObject::tr("Ile Minde - Esthar","49") << QObject::tr("D�sert Kashkabald - Esthar","50") << QObject::tr("Ile Paradisiaque - Esthar","51") << QObject::tr("Pic de Talle - Esthar","52") << QObject::tr("Atoll Shalmal - Esthar","53") << QObject::tr("Vall�e de Lolestern - Centra","54") << QObject::tr("Aiguille d'Almage - Centra","55") << QObject::tr("Vallon Lenown - Centra","56") << QObject::tr("Cap de l'espoir - Centra","57") << QObject::tr("Mont Yorn - Centra","58") << QObject::tr("Ile Pampa - Esthar","59") << QObject::tr("Val Serengetti - Centra","60") << QObject::tr("P�ninsule Nectalle - Centra","61") << QObject::tr("Centra Crater - Centra","62") << QObject::tr("Ile Poccarahi - Centra","63")
			<< QObject::tr("Biblioth�que - BGU","64") << QObject::tr("Entr�e - BGU","65") << QObject::tr("Salle de cours - BGU","66") << QObject::tr("Caf�t�ria - BGU","67") << QObject::tr("Niveau MD - BGU","68") << QObject::tr("Hall 1er �tage - BGU","69") << QObject::tr("Hall - BGU","70") << QObject::tr("Infirmerie - BGU","71") << QObject::tr("Dortoirs doubles - BGU","72") << QObject::tr("Dortoirs simples - BGU","73") << QObject::tr("Bureau proviseur - BGU","74") << QObject::tr("Parking - BGU","75") << QObject::tr("Salle de bal - BGU","76") << QObject::tr("Campus - BGU","77") << QObject::tr("Serre de combat - BGU","78") << QObject::tr("Zone secr�te - BGU","79")
			<< QObject::tr("Corridor - BGU","80") << QObject::tr("Temple - BGU","81") << QObject::tr("Pont - BGU","82") << QObject::tr("Villa Dincht - Balamb","83") << QObject::tr("H�tel - Balamb","84") << QObject::tr("Place centrale - Balamb","85") << QObject::tr("Place de la gare - Balamb","86") << QObject::tr("Port - Balamb","87") << QObject::tr("R�sidence - Balamb","88") << QObject::tr("Train","89") << QObject::tr("Voiture","90") << QObject::tr("Vaisseau","91") << QObject::tr("Mine de souffre","92") << QObject::tr("Place du village - Dollet","93") << QObject::tr("Zuma Beach","94") << QObject::tr("Port - Dollet","95")
			<< QObject::tr("Pub - Dollet","96") << QObject::tr("H�tel - Dollet","97") << QObject::tr("R�sidence - Dollet","98") << QObject::tr("Tour satellite - Dollet","99") << QObject::tr("Refuge montagneux - Dollet","100") << QObject::tr("Centre ville - Timber","101") << QObject::tr("Cha�ne de TV - Timber","102") << QObject::tr("Base des Hiboux - Timber","103") << QObject::tr("Pub - Timber","104") << QObject::tr("H�tel - Timber","105") << QObject::tr("Train - Timber","106") << QObject::tr("R�sidence - Timber","107") << QObject::tr("Ecran g�ant - Timber","108") << QObject::tr("Centre de presse - Timber","109") << QObject::tr("For�t de Timber","110") << QObject::tr("Entr�e - Fac de Galbadia","111")
			<< QObject::tr("Station Fac de Galbadia","112") << QObject::tr("Hall - Fac de Galbadia","113") << QObject::tr("Corridor - Fac de Galbadia","114") << QObject::tr("Salle d'attente - Fac Galbadia","115") << QObject::tr("Salle de cours - Fac Galbadia","116") << QObject::tr("Salle de r�union - Fac Galbadia","117") << QObject::tr("Dortoirs - Fac de Galbadia","118") << QObject::tr("Ascenseur - Fac de Galbadia","119") << QObject::tr("Salle recteur - Fac Galbadia","120") << QObject::tr("Auditorium - Fac de Galbadia","121") << QObject::tr("Stade - Fac de Galbadia","122") << QObject::tr("Stand - Fac de Galbadia","123") << QObject::tr("2nde entr�e - Fac Galbadia","124") << QObject::tr("Gymnase - Fac de Galbadia","125") << QObject::tr("Palais pr�sident - Deling City","126") << QObject::tr("Manoir Caraway - Deling City","127")
			<< QObject::tr("Gare - Deling City","128") << QObject::tr("Place centrale - Deling City","129") << QObject::tr("H�tel - Deling City","130") << QObject::tr("Bar - Deling City","131") << QObject::tr("Sortie - Deling City","132") << QObject::tr("Parade - Deling City","133") << QObject::tr("Egout - Deling City","134") << QObject::tr("Prison du d�sert - Galbadia","135") << QObject::tr("D�sert","136") << QObject::tr("Base des missiles","137") << QObject::tr("Village de Winhill","138") << QObject::tr("Pub - Winhill","139") << QObject::tr("Maison vide - Winhill","140") << QObject::tr("Manoir - Winhill","141") << QObject::tr("R�sidence - Winhill","142") << QObject::tr("H�tel - Winhill","143")
			<< QObject::tr("Voiture - Winhill","144") << QObject::tr("Tombe du roi inconnu","145") << QObject::tr("Horizon","146") << QObject::tr("Habitations - Horizon","147") << QObject::tr("Ecrans solaires - Horizon","148") << QObject::tr("Villa du maire - Horizon","149") << QObject::tr("Usine - Horizon","150") << QObject::tr("Salle des f�tes - Horizon","151") << QObject::tr("H�tel - Horizon","152") << QObject::tr("R�sidence - Horizon","153") << QObject::tr("Gare - Horizon","154") << QObject::tr("Aqueduc d'Horizon","155") << QObject::tr("Station baln�aire","156") << QObject::tr("Salt Lake","157") << QObject::tr("B�timent myst�rieux","158") << QObject::tr("Esthar City","159")
			<< QObject::tr("Laboratoire Geyser - Esthar","160") << QObject::tr("A�rodrome - Esthar","161") << QObject::tr("Lunatic Pandora approche","162") << QObject::tr("R�sidence pr�sident - Esthar","163") << QObject::tr("Hall - R�sidence pr�sident","164") << QObject::tr("Couloir - R�sidence pr�sident","165") << QObject::tr("Bureau - R�sidence pr�sident","166") << QObject::tr("Accueil - Labo Geyser","167") << QObject::tr("Laboratoire Geyser","168") << QObject::tr("Deleted","169") << QObject::tr("Lunar Gate","170") << QObject::tr("Parvis - Lunar Gate","171") << QObject::tr("Glaci�re - Lunar gate","172") << QObject::tr("Mausol�e - Esthar","173") << QObject::tr("Entr�e - Mausol�e","174") << QObject::tr("Pod de confinement - Mausol�e","175")
			<< QObject::tr("Salle de contr�le - Mausol�e","176") << QObject::tr("Tears Point","177") << QObject::tr("Labo Lunatic Pandora","178") << QObject::tr("Zone d'atterrissage de secours","179") << QObject::tr("Zone d'atterrissage officielle","180") << QObject::tr("Lunatic Pandora","181") << QObject::tr("Site des fouilles - Centra","182") << QObject::tr("Orphelinat","183") << QObject::tr("Salle de jeux - Orphelinat","184") << QObject::tr("Dortoir - Orphelinat","185") << QObject::tr("Jardin - Orphelinat","186") << QObject::tr("Front de mer - Orphelinat","187") << QObject::tr("Champ - Orphelinat","188") << QObject::tr("Ruines de Centra","189") << QObject::tr("Entr�e - Fac de Trabia","190") << QObject::tr("Cimeti�re - Fac de Trabia","191")
			<< QObject::tr("Garage - Fac de Trabia","192") << QObject::tr("Campus - Fac Trabia","193") << QObject::tr("Amphith�atre - Fac de Trabia","194") << QObject::tr("Stade - Fac de Trabia","195") << QObject::tr("D�me myst�rieux","196") << QObject::tr("Ville du d�sert - Shumi Village","197") << QObject::tr("Ascenseur - Shumi Village","198") << QObject::tr("Shumi Village","199") << QObject::tr("Habitation - Shumi Village","200") << QObject::tr("R�sidence - Shumi Village","201") << QObject::tr("Habitat - Shumi Village","202") << QObject::tr("H�tel - Shumi Village","203") << QObject::tr("Trabia canyon","204") << QObject::tr("Vaisseau des Seeds blancs","205") << QObject::tr("Navire des Seeds Blancs","206") << QObject::tr("Cabine - Navire Seeds blancs","207")
			<< QObject::tr("Cockpit - Hydre","208") << QObject::tr("Si�ge passager - Hydre","209") << QObject::tr("Couloir - Hydre","210") << QObject::tr("Hangar - Hydre","211") << QObject::tr("Acc�s - Hydre","212") << QObject::tr("Air Room - Hydre","213") << QObject::tr("Salle de pression - Hydre","214") << QObject::tr("Centre de recherches Deep Sea","215") << QObject::tr("Laboratoire - Deep Sea","216") << QObject::tr("Salle de travail - Deep Sea","217") << QObject::tr("Fouilles - Deep Sea","218") << QObject::tr("Salle de contr�le - Base lunaire","219") << QObject::tr("Centre m�dical - Base lunaire","220") << QObject::tr("Pod - Base lunaire","221") << QObject::tr("Dock - Base lunaire","222") << QObject::tr("Passage - Base lunaire","223")
			<< QObject::tr("Vestiaire - Base lunaire","224") << QObject::tr("Habitats - Base lunaire","225") << QObject::tr("Hyper Espace","226") << QObject::tr("For�t Chocobo","227") << QObject::tr("Jungle","228") << QObject::tr("Citadelle d'Ultimecia - Vestibule","229") << QObject::tr("Citadelle d'Ultimecia - Hall","230") << QObject::tr("Citadelle d'Ultimecia - Terrasse","231") << QObject::tr("Citadelle d'Ultimecia - Cave","232") << QObject::tr("Citadelle d'Ultimecia - Couloir","233") << QObject::tr("El�vateur - Citadelle","234") << QObject::tr("Escalier - Citadelle d'Ultimecia","235") << QObject::tr("Salle du tr�sor - Citadelle","236") << QObject::tr("Salle de rangement - Citadelle","237") << QObject::tr("Citadelle d'Ultimecia - Galerie","238") << QObject::tr("Citadelle d'Ultimecia - Ecluse","239")
			<< QObject::tr("Citadelle - Armurerie","240") << QObject::tr("Citadelle d'Ultimecia - Prison","241") << QObject::tr("Citadelle d'Ultimecia - Foss�","242") << QObject::tr("Citadelle d'Ultimecia - Jardin","243") << QObject::tr("Citadelle d'Ultimecia - Chapelle","244") << QObject::tr("Clocher - Citadelle d'Ultimecia","245") << QObject::tr("Chambre d'Ultimecia - Citadelle","246") << QString("???") << QObject::tr("Citadelle d'Ultimecia","248") << QObject::tr("Salle d'initiation","249") << QObject::tr("Reine des cartes","250") << QString("???") << QString("???") << QString("???") << QString("???") << QString("???");

	weapons << QObject::tr("Pistolame") << QObject::tr("Nacre Blade") << QObject::tr("Dragon Blade") << QObject::tr("Sabreur") << QObject::tr("Katana") << QObject::tr("Kendo") << QObject::tr("Lionheart")
			<< QObject::tr("Metal Gloves") << QObject::tr("Maverick") << QObject::tr("Gauntlets") << QObject::tr("Ehrgeiz")
			<< QObject::tr("W.W.West") << QObject::tr("Roosevelt") << QObject::tr("Bertha") << QObject::tr("Steel Gun")
			<< QObject::tr("Gibet") << QObject::tr("Totally S.M.") << QObject::tr("Red Scorpio") << QObject::tr("Smiley")
			<< QObject::tr("Rotator") << QObject::tr("Walkyrie") << QObject::tr("Ninja Sun") << QObject::tr("Pt�rodactyle") << QObject::tr("Tron�onneur")
			<< QObject::tr("Nunchak Red") << QObject::tr("Nunchak Blue") << QObject::tr("Islam Star") << QObject::tr("Sagaie")
			<< QObject::tr("Hyperion") << QObject::tr("Nada") << QObject::tr("Kalachnikov") << QObject::tr("Katal") << QObject::tr("Harpoon");

	names << QObject::tr("Squall") << QObject::tr("Zell") << QObject::tr("Irvine") << QObject::tr("Quistis") << QObject::tr("Linoa")
			<< QObject::tr("Selphie") << QObject::tr("Seifer") << QObject::tr("Edea") << QObject::tr("Laguna") << QObject::tr("Kiros")
			<< QObject::tr("Ward") << "" << QObject::tr("Cronos") << QObject::tr("MiniMog") << QObject::tr("Boko") << QObject::tr("Angel");

	gfnames << QObject::tr("Golgotha","gf") << QObject::tr("Shiva","gf") << QObject::tr("Ifrit","gf") << QObject::tr("Ondine","gf")
			<< QObject::tr("Taurus","gf") << QObject::tr("Nosferatu","gf") << QObject::tr("Ahuri","gf") << QObject::tr("Leviathan","gf")
			<< QObject::tr("Z�phyr","gf") << QObject::tr("Cerberus","gf") << QObject::tr("Alexander","gf") << QObject::tr("Helltrain","gf")
			<< QObject::tr("Bahamut","gf") << QObject::tr("Pampa","gf") << QObject::tr("Tomberry","gf") << QObject::tr("Orbital","gf");
	
	zellLB << QObject::tr("Top Punch") << QObject::tr("Feinte") << QObject::tr("Achille") << QObject::tr("Forcing") << QObject::tr("Delphinium")
			<< QObject::tr("Apesanteur") << QObject::tr("Fahreinheit") << QObject::tr("Stratosph�re") << QObject::tr("Trap�ze") << QObject::tr("Global Wave");
	
	irvineLB << QObject::tr("Furioso") << QObject::tr("Fluxion") << QObject::tr("Fracas") << QObject::tr("Fusion")
			<< QObject::tr("Barbacane") << QObject::tr("Mach 4") << QObject::tr("Apog�e") << QObject::tr("Percuteur");
	
	quistisLB << QObject::tr("Fov�a") << QObject::tr("Ultra Waves") << QObject::tr("Firmament") << QObject::tr("Freak")
			<< QObject::tr("D�g�n�rator") << QObject::tr("Fr�on") << QObject::tr("Micro Missiles") << QObject::tr("Acid")
			<< QObject::tr("Mitraille") << QObject::tr("Dead Heat") << QObject::tr("Infection") << QObject::tr("Mistral")
			<< QObject::tr("Laser") << QObject::tr("Mother") << QObject::tr("Shockwave") << QObject::tr("Outerspace");

	rinoaLB << QObject::tr("Dingo") << QObject::tr("Shepherd") << QObject::tr("Dachshund") << QObject::tr("Borzo�")
			<< QObject::tr("La�ka") << QObject::tr("Nordfolk") << QObject::tr("S�l�nium") << QObject::tr("Phantasm");

	cards << QObject::tr("Bogomile") << QObject::tr("Fungus") << QObject::tr("Elmidea") << QObject::tr("Nocturnus") << QObject::tr("Incube") << QObject::tr("Aphide")
			<< QObject::tr("Elastos") << QObject::tr("Diodon") << QObject::tr("Carnid�a") << QObject::tr("Larva") << QObject::tr("Gallus") << QObject::tr("Orchida")
			<< QObject::tr("Schizo�d") << QObject::tr("Licorne") << QObject::tr("Xylopode") << QObject::tr("Koatl") << QObject::tr("Malaku") << QObject::tr("Arconada")
			<< QObject::tr("Formicide") << QObject::tr("Feng") << QObject::tr("H�ra") << QObject::tr("Selek") << QObject::tr("Weevil") << QObject::tr("Scavenger")
			<< QObject::tr("Ad�phage") << QObject::tr("Phantom") << QObject::tr("Satyrux") << QObject::tr("Trogiidae") << QObject::tr("Barbarian")
			<< QObject::tr("Berseker") << QObject::tr("Pampa","card") << QObject::tr("Tomberry","card") << QObject::tr("C�l�bis") << QObject::tr("Eiffel") << QObject::tr("Cariatide")
			<< QObject::tr("T-rex") << QObject::tr("Succube") << QObject::tr("Tikal") << QObject::tr("Wendigo") << QObject::tr("Marsupial") << QObject::tr("Draconus")
			<< QObject::tr("Moloch") << QObject::tr("Ao") << QObject::tr("Polyphage") << QObject::tr("Ekarissor") << QObject::tr("Kanibal") << QObject::tr("Chimaira")
			<< QObject::tr("Koyo K") << QObject::tr("Protesis") << QObject::tr("Pikasso") << QObject::tr("Xylomid") << QObject::tr("Griffon") << QObject::tr("Sulfor")
			<< QObject::tr("Tomberry Sr") << QObject::tr("Wedge/Biggs") << QObject::tr("Fujin/Raijin") << QObject::tr("Sulfura") << QObject::tr("Goliath")
			<< QObject::tr("Lygus") << QObject::tr("�corch�") << QObject::tr("Iguanor") << QObject::tr("Hornet") << QObject::tr("Flotix") << QObject::tr("Cyanide")
			<< QObject::tr("Shumi") << QObject::tr("Krystal") << QObject::tr("Alienator") << QObject::tr("Pampa Sr") << QObject::tr("Acron") << QObject::tr("Agamemnon")
			<< QObject::tr("Anakronox") << QObject::tr("Mithra") << QObject::tr("Acarnan") << QObject::tr("Omniborg") << QObject::tr("Attila") << QObject::tr("Fabryce")
			<< QObject::tr("Monarch") << QObject::tr("Grochocobo","card") << QObject::tr("Angel","card") << QObject::tr("Gilgamesh","card") << QObject::tr("Minimog","card") << QObject::tr("Chicobo","card")
			<< QObject::tr("Golgotha","card") << QObject::tr("Shiva","card") << QObject::tr("Ifrit","card") << QObject::tr("Ondine","card") << QObject::tr("Tauros","card") << QObject::tr("Taurux","card")
			<< QObject::tr("Ahuri","card") << QObject::tr("Nosferatu","card") << QObject::tr("Leviathan","card") << QObject::tr("Odin","card") << QObject::tr("Z�phyr","card") << QObject::tr("Cerb�res")
			<< QObject::tr("Alexander","card") << QObject::tr("Ph�nix","card") << QObject::tr("Bahamut","card") << QObject::tr("Helltrain","card") << QObject::tr("Orbital","card") << QObject::tr("Ward")
			<< QObject::tr("Kiros") << QObject::tr("Laguna") << QObject::tr("Selphie") << QObject::tr("Quistis") << QObject::tr("Irvine") << QObject::tr("Zell")
			<< QObject::tr("Linoa") << QObject::tr("Edea") << QObject::tr("Seifer") << QObject::tr("Squall");

	ennemies << QObject::tr("Dummy", "Ennemy") << QObject::tr("ExoSkelet", "Ennemy") << QObject::tr("Incube", "Ennemy") << QObject::tr("Malaku", "Ennemy")
			 << QObject::tr("Bogomile", "Ennemy") << QObject::tr("Koatl", "Ennemy") << QObject::tr("Xylopode", "Ennemy") << QObject::tr("Barbarian", "Ennemy")
			 << QObject::tr("Pikasso", "Ennemy") << QObject::tr("Licorne", "Ennemy") << QObject::tr("Schizo�d", "Ennemy") << QObject::tr("Brahman", "Ennemy")
			 << QObject::tr("Shiva", "Ennemy") << QObject::tr("Satyrux", "Ennemy") << QObject::tr("Arconada", "Ennemy") << QObject::tr("Orchida", "Ennemy")
			 << QObject::tr("Gallus", "Ennemy") << QObject::tr("Larva", "Ennemy") << QObject::tr("Nocturnus", "Ennemy") << QObject::tr("Tikal", "Ennemy")
			 << QObject::tr("Diodon", "Ennemy") << QObject::tr("Phantom", "Ennemy") << QObject::tr("Elastos", "Ennemy") << QObject::tr("Formicide", "Ennemy")
			 << QObject::tr("Polyphage", "Ennemy") << QObject::tr("Carnidea", "Ennemy") << QObject::tr("Protesis", "Ennemy") << QObject::tr("Scavenger", "Ennemy")
			 << QObject::tr("Elmidea", "Ennemy") << QObject::tr("H�ra", "Ennemy") << QObject::tr("Acron", "Ennemy") << QObject::tr("Eiffel", "Ennemy")
			 << QObject::tr("Wendigo", "Ennemy") << QObject::tr("Aphide", "Ennemy") << QObject::tr("Ecorch�", "Ennemy") << QObject::tr("Berserker", "Ennemy")
			 << QObject::tr("Ad�phage", "Ennemy") << QObject::tr("Selek", "Ennemy") << QObject::tr("Krystal", "Ennemy") << QObject::tr("Gangr�ne", "Ennemy")
			 << QObject::tr("Fatima", "Ennemy") << QObject::tr("Moloch", "Ennemy") << QObject::tr("Weevil", "Ennemy") << QObject::tr("Succube", "Ennemy")
			 << QObject::tr("C�l�bis", "Ennemy") << QObject::tr("Trogiidae", "Ennemy") << QObject::tr("Ao", "Ennemy") << QObject::tr("Chimaira", "Ennemy")
			 << QObject::tr("Xylomid", "Ennemy") << QObject::tr("Ekarissor", "Ennemy") << QObject::tr("Kanibal", "Ennemy") << QObject::tr("T-Rex", "Ennemy")
			 << QObject::tr("Griffon", "Ennemy") << QObject::tr("Feng", "Ennemy") << QObject::tr("Cariatide", "Ennemy") << QObject::tr("Pampa", "Ennemy")
			 << QObject::tr("Tomberry", "Ennemy") << QObject::tr("Marsupial", "Ennemy") << QObject::tr("Fungus", "Ennemy") << QObject::tr("Draconus", "Ennemy")
			 << QObject::tr("Koyo K", "Ennemy") << QObject::tr("Ifrit", "Ennemy") << QObject::tr("Taurux", "Ennemy") << QObject::tr("Tauros", "Ennemy")
			 << QObject::tr("Commandeur", "Ennemy") << QObject::tr("Cerb�res", "Ennemy") << QObject::tr("Nosferatu", "Ennemy") << QObject::tr("Bahamut", "Ennemy")
			 << QObject::tr("Odyssey", "Ennemy") << QObject::tr("Templier", "Ennemy") << QObject::tr("Odin", "Ennemy") << QObject::tr("Galbadien", "Ennemy")
			 << QObject::tr("Elite-T", "Ennemy") << QObject::tr("Wedge", "Ennemy") << QObject::tr("Biggs", "Ennemy") << QObject::tr("Doublure", "Ennemy")
			 << QObject::tr("Trooper", "Ennemy") << QObject::tr("Norg", "Ennemy") << QObject::tr("S-Borg", "Ennemy") << QObject::tr("T-Borg", "Ennemy")
			 << QObject::tr("Tupolev", "Ennemy") << QObject::tr("Spootnik", "Ennemy") << QObject::tr("Gunblade (1)", "Ennemy") << QObject::tr("Tomberry Sr", "Ennemy")
			 << QObject::tr("Pampa Senior", "Ennemy") << QObject::tr("Seifer (1)", "Ennemy") << QObject::tr("Seifer (2)", "Ennemy") << QObject::tr("Seifer (3)", "Ennemy")
			 << QObject::tr("Edea (1)", "Ennemy") << QObject::tr("Alienator (violet)", "Ennemy") << QObject::tr("Monarch", "Ennemy") << QObject::tr("Sulfura", "Ennemy")
			 << QObject::tr("Goliath", "Ennemy") << QObject::tr("Iguanor", "Ennemy") << QObject::tr("Agamemnon", "Ennemy") << QObject::tr("Lygus", "Ennemy")
			 << QObject::tr("Cujo", "Ennemy") << QObject::tr("Alienator (vert)", "Ennemy") << QObject::tr("Alienator (jaune)", "Ennemy") << QObject::tr("Cyanide", "Ennemy")
			 << QObject::tr("Edea (2)", "Ennemy") << QObject::tr("Omniborg (1)", "Ennemy") << QObject::tr("Omniborg (2)", "Ennemy") << QObject::tr("Hornet", "Ennemy")
			 << QObject::tr("Hornet (zombie)", "Ennemy") << QObject::tr("Anakronox", "Ennemy") << QObject::tr("A-G Pod", "Ennemy") << QObject::tr("A-D Pod", "Ennemy")
			 << QObject::tr("ParaBorg", "Ennemy") << QObject::tr("Flotix", "Ennemy") << QObject::tr("Bibendum", "Ennemy") << QObject::tr("Alienator (rouge)", "Ennemy")
			 << QObject::tr("Adel", "Ennemy") << names.at(RINOA) << QObject::tr("Minotaure", "Ennemy") << QObject::tr("N�cromancienne (1)", "Ennemy")
			 << QObject::tr("N�cromancienne (2)", "Ennemy") << QObject::tr("N�cromancienne (3)", "Ennemy") << QObject::tr("UFO", "Ennemy") << QObject::tr("Fujin (1)", "Ennemy")
			 << QObject::tr("Raijin (1)", "Ennemy") << QObject::tr("Ultimecia (1)", "Ennemy") << names.at(GRIEVER) << QObject::tr("(Sans nom)", "Ennemy") << QObject::tr("Ultimecia (2)", "Ennemy")
			 << QObject::tr("H�lix", "Ennemy") << QObject::tr("Ultimecia (3)", "Ennemy") << QObject::tr("Ultimecia (4)", "Ennemy") << QObject::tr("Seifer (4)", "Ennemy") << QObject::tr("Jason", "Ennemy")
			 << QObject::tr("Attila", "Ennemy") << QObject::tr("Sulfor", "Ennemy") << QObject::tr("Acarnan", "Ennemy") << QObject::tr("Fabryce", "Ennemy")
			 << QObject::tr("Wedge", "Ennemy") << QObject::tr("Biggs", "Ennemy") << QObject::tr("Fujin (2)", "Ennemy") << QObject::tr("Raijin (2)", "Ennemy")
			 << QObject::tr("UFO (Mandy Beach)", "Ennemy") << QObject::tr("UFO (Winhill)", "Ennemy") << QObject::tr("UFO (Trabia)", "Ennemy") << QObject::tr("UFO (D�sert Kashkabald)", "Ennemy")
			 << QObject::tr("Gunblade (2)", "Ennemy") << QObject::tr("Soldat", "Ennemy");
}

QMap<int, QIcon> Data::abilityIcons()
{
	QMap<int, QIcon> icons;
	for(int i=0 ; i<6 ; ++i)
		icons.insert(i, QIcon(QString(":/images/icons/capacity%1.png").arg(i)));
	return icons;
}

void Data::fillAbilities(QComboBox *comboBox, const QMap<int, QIcon> &icons)
{
	int abilityCount = Data::abilities.size();
	for(int i=1 ; i<abilityCount ; ++i)
		comboBox->addItem(icons.value(Data::abilityType(i)), Data::abilities.at(i), i);
}

qint8 Data::abilityType(quint8 abilityID)
{
	if(abilityID >= 01 && abilityID <= 19)	return 0;
	if(abilityID >= 20 && abilityID <= 38)	return 1;
	if(abilityID >= 39 && abilityID <= 77)	return 2;
	if(abilityID >= 78 && abilityID <= 82)	return 3;
	if(abilityID >= 83 && abilityID <= 91)	return 4;
	if(abilityID >= 92 && abilityID <= 120)	return 5;
	return 0;
}

quint8 Data::itemType(quint8 itemID)
{
	if(itemID >= 01 && itemID <= 17)	return 0;
	if((itemID >= 18 && itemID <= 21)
		|| (itemID >= 30 && itemID <= 32)
		|| (itemID >= 165 && itemID <= 168))	return 1;
	if((itemID >= 22 && itemID <= 29)
		|| (itemID >= 109 && itemID <= 164)
		|| (itemID >= 169 && itemID <= 176))	return 2;
	if(itemID >= 33 && itemID <= 35)	return 5;
	if(itemID >= 36 && itemID <= 100)	return 4;
	if(itemID >= 101 && itemID <= 108)	return 3;
	return 6;
}

//Thanks to Qhimm

const quint8 Data::apsTab[116] =
{
	0,
	50,		//HP-J
	50,		//Str-J
	50,		//Vit-J
	50,		//Mag-J
	50,		//Spr-J
	120,	//Spd-J
	200,	//Eva-J
	120,	//Hit-J
	200,	//Luck-J
	160,	//Elem-Atk-J
	160,	//ST-Atk-J
	100,	//Elem-Def-J
	100,	//ST-Def-J
	130,	//Elem-Defx2
	180,	//Elem-Defx4
	130,	//ST-Def-Jx2
	180,	//ST-Def-Jx4
	150,	//Abilityx3
	200,	//Abilityx4
	1,		//Magic(20)
	1,		//GF
	1,		//Draw
	1,		//Item
	0,		//???
	40,		//Card
	60,		//Doom
	60,		//MadRush
	100,	//Treatment
	100,	//Defend
	100,	//Darkside
	200,	//Recover
	80,		//Absorb
	200,	//Revive
	100,	//LVDown
	100,	//LVUp
	100,	//Kamikaze
	100,	//Devour
	0,		//MiniMog
	60,		//HP+20%(39)
	120,	//HP+40%
	240,	//HP+80%
	60,		//Str+20%
	120,	//Str+40%
	240,	//Str+60%
	60,		//Vit+20%
	120,	//Vit+40%
	240,	//Vit+60%
	60,		//Mag+20%
	120,	//Mag+40%
	240,	//Mag+60%
	60,		//Spr+20%
	120,	//Spr+40%
	240,	//Spr+60%
	150,	//Spd+20%
	200,	//Spd+40%
	150,	//Eva+30%
	200,	//Luck+50%
	200,	//Mug
	200,	//MedData
	200,	//Counter
	0,		//ReturnDamage
	100,	//Cover
	160,	//Initiative
	200,	//MoveHP-Up
	100,	//HPBonus
	100,	//StrBonus
	100,	//VitBonus
	100,	//MagBonus
	100,	//SprBonus
	250,	//Auto-Protect
	250,	//Auto-Shell
	250,	//Auto-Reflect
	250,	//Auto-Haste
	150,	//Auto-Potion
	250,	//Expendx2-1
	250,	//Expendx3-1
	0,		//Ribbon
	200,	//Alert(78)
	40,		//Move-Find
	30,		//Enc-Half
	100,	//Enc-None
	250,	//RareItem
	40,		//SumMag+10%(83)
	70,		//SumMag+20%
	140,	//SumMag+30%
	200,	//SumMag+40%
	40,		//GFHP+10%
	70,		//GFHP+20%
	140,	//GFHP+30%
	200,	//GFHP+40%
	10,		//Boost
	150,	//Haggle(92)
	150,	//Sell-High
	150,	//Familiar
	200,	//CallShop
	150,	//JunkShop
	30,		//TMag-RF
	30,		//IMag-RF
	30,		//FMag-RF
	30,		//LMag-RF
	30,		//TimeMag-RF
	60,		//STMag-RF
	30,		//SuptMag-RF
	200,	//ForbidMag-RF
	30,		//RecovMed-RF
	30,		//STMed-RF
	30,		//Ammo-RF
	30,		//Tool-RF
	200,	//ForbidMed-RF
	30,		//GFRecovMed-RF
	30,		//GFAblMed-RF
	60,		//MidMag-RF
	60,		//HighMag-RF
	120,	//MedLVUp
	80,		//CardMod
};

const quint8 Data::innateAbilities[16][22] =
{
	{//Golgotha
		83,	// SumMag+10%
		84,	// SumMag+20%
		85,	// SumMag+30%
		87,	// GFHP+10%
		88,	// GFHP+20%
		91,	// Boost
		97,	// T Mag-RF
		112,// Mid Mag-RF
		1,	// HP-J
		48,	// Mag+20%
		49,	// Mag+40%
		10,	// Elem-Atk-J
		3,	// Vit-J
		12,	// Elem-Def-J
		14,	// Elem-Defx2
		25,	// Card
		115,// Card Mod
		4,	// Mag-J
		23,	// Item
		20,	// Magic
		21,	// GF
		22, //Draw
	},
{//Shiva
		83,	// SumMag+10%
		84,	// SumMag+20%
		85,	// SumMag+30%
		87,	// GFHP+10%
		88,	// GFHP+20%
		23,	//Item
		91,	//Boost
		98,	//IMag-RF
		3,	//Vit-J
		45,	//Vit+20%
		46,	//Vit+40%
		51,	//Spr+20%
		52,	//Spr+40%
		12,	//Elem-Def-J
		14,	//Elem-Defx2
		2,	//Str-J
		10,	//Elem-Atk-J
		26,	//Doom
		5,	//Spr-J
		20,	//Magic
		21,	//GF
		22, //Draw
	},
{//Ifrit
		83,	//SumMag+10%
		84,	//SumMag+20%
		85,	//SumMag+30%
		87,	//GFHP+10%
		88,	//GFHP+20%
		89,	//GFHP+30%
		91,	//Boost
		99,	//FMag-RF
		107,//Ammo-RF
		42,	//Str+20%
		43,	//Str+40%
		10,	//Elem-Atk-J
		66,	//StrBonus
		1,	//HP-J
		23,	//Item
		12,	//Elem-Def-J
		14,	//Elem-Defx2
		27,	//MadRush
		2,	//Str-J
		20,	//Magic
		21,	//GF
		22, //Draw
	},
{//Ondine
		87,	//GFHP+10%
		88,	//GFHP+20%
		108,//Tool-RF
		83,	//SumMag+10%
		84,	//SumMag+20%
		85,	//SumMag+30%
		91,	//Boost
		100,//LMag-RF
		106,//STMed-RF
		48,	//Mag+20%
		49,	//Mag+40%
		11,	//ST-Atk-J
		68,	//MagBonus
		23,	//Item
		13,	//ST-Def-J
		16,	//ST-Def-Jx2
		28,	//Treatment
		79,	//Move-Find
		4,	//Mag-J
		20,	//Magic
		21,	//GF
		22, //Draw
	},
{//Taurus
		83,	//SumMag+10%
		84,	//SumMag+20%
		85,	//SumMag+30%
		87,	//GFHP+10%
		88,	//GFHP+20%
		89,	//GFHP+30%
		91,	//Boost
		39,	//HP+20%
		40,	//HP+40%
		41,	//HP+80%
		65,	//HPBonus
		2,	//Str-J
		10,	//Elem-Atk-J
		5,	//Spr-J
		12,	//Elem-Def-J
		23,	//Item
		62,	//Cover
		29,	//Defend
		1,	//HP-J
		20,	//Magic
		21,	//GF
		22, //Draw
	},
{//Nosferatu
		87,	//GFHP+10%
		88,	//GFHP+20%
		89,	//GFHP+30%
		101,//TimeMag-RF
		102,//STMag-RF
		1,	//HP-J
		39,	//HP+20%
		40,	//HP+40%
		41,	//HP+80%
		4,	//Mag-J
		48,	//Mag+20%
		49,	//Mag+40%
		23,	//Item
		8,	//Hit-J
		80,	//Enc-Half
		81,	//Enc-None
		30,	//Darkside
		58,	//Mug
		18,	//Abilityx3
		20,	//Magic
		21,	//GF
		22, //Draw
	},
{//Ahuri
		87,	//GFHP+10%
		88,	//GFHP+20%
		89,	//GFHP+30%
		105,//RecovMed-RF
		45,	//Vit+20%
		46,	//Vit+40%
		67,	//VitBonus
		1,	//HP-J
		39,	//HP+20%
		40,	//HP+40%	(?)
		4,	//Mag-J
		11,	//ST-Atk-J
		13,	//ST-Def-J
		16,	//ST-Def-Jx2
		60,	//Counter
		72,	//Auto-Reflect
		23,	//Item
		18,	//Abilityx3
		3,	//Vit-J
		20,	//Magic
		21,	//GF
		22, //Draw
	},
{//Leviathan
		87,	//GFHP+10%
		88,	//GFHP+20%
		89,	//GFHP+30%
		83,	//SumMag+10%
		84,	//SumMag+20%
		85,	//SumMag+30%
		91,	//Boost
		103,//SuptMag-RF
		110,//GFRecovMed-RF
		51,	//Spr+20%
		52,	//Spr+40%
		69,	//SprBonus
		5,	//Spr-J
		14,	//Elem-Defx2
		4,	//Mag-J
		10,	//Elem-Atk-J
		74,	//Auto-Potion
		31,	//Recover
		23,	//Item
		20,	//Magic
		21,	//GF
		22, //Draw
	},
{//Z�phyr
		83,	//SumMag+10%
		84,	//SumMag+20%
		85,	//SumMag+30%
		87,	//GFHP+10%
		88,	//GFHP+20%
		89,	//GFHP+30%
		91,	//Boost
		6,	//Spd-J
		54,	//Spd+20%
		55,	//Spd+40%
		42,	//Str+20%
		43,	//Str+40%
		2,	//Str-J
		12,	//Elem-Def-J
		14,	//Elem-Defx2
		10,	//Elem-Atk-J
		63,	//Initiative
		32,	//Absorb
		23,	//Item
		20,	//Magic
		21,	//GF
		22, //Draw
	},
{//Cerberus
		87,	//GFHP+10%
		88,	//GFHP+20%
		89,	//GFHP+30%
		6,	//Spd-J
		54,	//Spd+20%
		55,	//Spd+40%
		73,	//Auto-Haste
		5,	//Spr-J
		13,	//ST-Def-J
		16,	//ST-Def-Jx2
		17,	//ST-Def-Jx4
		11,	//ST-Atk-J
		18,	//Abilityx3
		2,	//Str-J
		78,	//Alert
		4,	//Mag-J
		75,	//Expendx2-1
		8,	//Hit-J
		23,	//Item
		20,	//Magic
		21,	//GF
		22, //Draw
	},
{//Alexander
		87,	//GFHP+10%
		88,	//GFHP+20%
		89,	//GFHP+30%
		83,	//SumMag+10%
		84,	//SumMag+20%
		85,	//SumMag+30%
		91,	//Boost
		59,	//MedData
		114,//MedLVUp
		51,	//Spr+20%
		52,	//Spr+40%
		113,//HighMag-RF
		18,	//Abilityx3
		10,	//Elem-Atk-J
		14,	//Elem-Defx2
		15,	//Elem-Defx4
		5,	//Spr-J
		33,	//Revive
		23,	//Item
		20,	//Magic
		21,	//GF
		22, //Draw
	},
{//Helltrain
		83,	//SumMag+10%
		84,	//SumMag+20%
		85,	//SumMag+30%
		86,	//SumMag+40%
		87,	//GFHP+10%
		88,	//GFHP+20%
		89,	//GFHP+30%
		90,	//GFHP+40%
		91,	//Boost
		71,	//Auto-Shell
		32,	//Absorb
		30,	//Darkside
		96,	//JunkShop
		109,//ForbidMed-RF
		15,	//Elem-Defx4
		17,	//ST-Def-Jx4
		23,	//Item
		10,	//Elem-Atk-J
		11,	//ST-Atk-J
		20,	//Magic
		21,	//GF
		22, //Draw
	},
{//Bahamut
		83,	//SumMag+10%
		84,	//SumMag+20%
		85,	//SumMag+30%
		86,	//SumMag+40%
		87,	//GFHP+10%
		88,	//GFHP+20%
		89,	//GFHP+30%
		90,	//GFHP+40%
		91,	//Boost
		58,	//Mug
		75,	//Expendx2-1
		70,	//Auto-Protect
		23,	//Item
		82,	//RareItem
		64,	//Move-HPUp
		44,	//Str+60%
		50,	//Mag+60%
		104,//ForbidMag-RF
		19,	//Abilityx4
		20,	//Magic
		21,	//GF
		22, //Draw
	},
{//Pampa
		87,	//GFHP+10%
		88,	//GFHP+20%
		89,	//GFHP+30%
		23,	//Item
		7,	//Eva-J
		56,	//Eva+30%
		75,	//Expendx2-1
		9,	//Luck-J
		57,	//Luck+50%
		29,	//Defend
		74,	//Auto-Potion
		63,	//Initiative
		65,	//HPBonus
		66,	//StrBonus
		67,	//VitBonus
		68,	//MagBonus
		69,	//SprBonus
		64,	//Move-HPUp
		36,	//Kamikaze
		20,	//Magic
		21,	//GF
		22, //Draw
	},
{//Tomberry
		83,	//SumMag+10%
		84,	//SumMag+20%
		85,	//SumMag+30%
		87,	//GFHP+10%
		88,	//GFHP+20%
		89,	//GFHP+30%
		91,	//Boost
		74,	//Auto-Potion
		64,	//Move-HPUp
		63,	//Initiative
		57,	//Luck+50%
		23,	//Item
		56,	//Eva+30%
		92,	//Haggle
		93,	//Sell-High
		94,	//Familiar
		95,	//CallShop
		34,	//LVDown
		35,	//LVUp
		20,	//Magic
		21,	//GF
		22, //Draw
	},
{//orbital
		83,	//SumMag+10%
		84,	//SumMag+20%
		85,	//SumMag+30%
		86,	//SumMag+40%
		87,	//GFHP+10%
		88,	//GFHP+20%
		89,	//GFHP+30%
		90,	//GFHP+40%
		91,	//Boost
		111,//GFAblMed-RF
		30,	//DarkSide
		27,	//MadRush
		8,	//Hit-J
		6,	//Spd-J
		7,	//Eva-J
		57,	//Luck+50%
		76,	//Expendx3-1
		37,	//Devour
		23,	//Item
		20,	//Magic
		21,	//GF
		22, //Draw
	},
};

QString Data::getCardsLocation(int i)
{
	QString location;
	int locID = Data::cardsLocation[i];
	if(locID==-1)		location = QObject::tr("Utilis�e");
	else if(locID==-2)	location = QObject::tr("Squall");
	else {
		location = Data::locations.at(locID);
		if(i>=200 && i<233)
			location.append(QObject::tr(" (carte %1)").arg(Data::cards.at(77+(i-200))));
	}
	return location;
}

const int Data::cardsLocation[256] = {
	-1,250,0,0,0,0,0,0,0,0,111,111,111,125,111,116,114,
	125,128,132,132,132,129,129,129,149,0,0,220,219,74,69,69,
	65,65,71,70,80,80,70,135,135,69,67,0,67,0,147,170,
	0,64,64,64,64,85,83,86,86,87,87,87,195,190,194,192,
	193,193,190,195,96,93,96,93,93,93,101,104,105,101,101,101,
	101,101,101,129,205,205,205,183,138,138,141,139,143,142,138,138,
	147,150,153,150,201,201,202,202,202,197,199,197,197,164,44,165,
	44,44,160,44,44,44,44,156,148,0,0,0,0,0,0,0,
	0,70,70,69,70,69,70,69,65,74,80,0,0,0,0,0,
	0,0,0,0,0,81,192,194,138,87,0,0,0,0,0,107,
	101,101,102,101,97,94,93,93,95,0,0,0,0,0,0,0,
	0,0,0,227,44,0,0,0,0,0,0,0,0,44,44,44,
	44,44,44,44,44,44,44,250/*(200)GroChocobo...*/,103,73,70,227,149,207,0/*Ifrit*/,96,
	0/*Tauros*/,0/*Taurux*/,74,0/*Nosferatu*/,74,0/*Odin*/,86,0/*Cerb�res*/,220,250,0/*Bahamut*/,250,0/*Orbital*/,164,250,225,
	190,80,250,88,127,183,74,163/*Squall(card)*/,0,0,0,0,0,0,0,-2,
	0,184,1,0,0,193,1,0,0,200,1,0,0,208,1
};

const cInt Data::momentLocation[403] = {
	cInt(0, -1),/*CD1*/ cInt(7, 71), cInt(12, 80), cInt(14, 66), cInt(16, 66), cInt(17, 66), cInt(19, 67), cInt(20, 92), cInt(21, 92), /*cInt(22, 89),*/ cInt(23, 92), cInt(24, 92), cInt(28, 92), cInt(30, 92), cInt(33, 65), cInt(34, 72),
	cInt(36, 70), cInt(38, 70), cInt(40, 90), cInt(45, 87), cInt(50, 91), cInt(55, 91), cInt(60, 91), cInt(65, 94), cInt(70, 93), cInt(75, 93), cInt(80, 93), cInt(81, 93), cInt(82, 93), cInt(83, 93), cInt(84, 93), cInt(92, 93),
	cInt(95, 100), cInt(100, 100), cInt(105, 100), cInt(110, 99), cInt(111, 99), cInt(115, 99), cInt(116, 99), cInt(117, 99), cInt(120, 99), cInt(122, 99), cInt(125, 99), cInt(135, 94), cInt(140, 70), cInt(142, 70), cInt(145, 74), cInt(150, 76),
	cInt(155, 76), cInt(170, 79), cInt(175, 78), cInt(177, 80), cInt(180, 73), cInt(195, 73), cInt(205, 65), cInt(216, 110), cInt(217, 110), cInt(218, 110), cInt(220, 110), cInt(222, 129), cInt(223, 130), cInt(224, 131), cInt(226, 131), cInt(228, 131),
	cInt(233, 130), cInt(235, 101), cInt(245, 103), cInt(255, 103), cInt(265, 103), cInt(270, 103), cInt(275, 101), cInt(280, 101), cInt(285, 102), cInt(290, 101), cInt(310, 182), cInt(315, 110), cInt(320, 111), cInt(321, 111), cInt(322, 115), cInt(323, 114),
	cInt(324, 113), cInt(328, 111), cInt(330, 111), cInt(333, 111), cInt(345, 111), cInt(348, 112), cInt(350, 129), cInt(351, 129), cInt(352, 129), cInt(353, 129), cInt(354, 127), cInt(356, 127), cInt(357, 127), cInt(358, 127), cInt(359, 129), cInt(360, 126),
	cInt(361, 126), cInt(362, 132), cInt(363, 126), cInt(364, 132), cInt(365, 127), cInt(366, 127), cInt(367, 129), cInt(368, 129), cInt(369, 132), cInt(370, 132), cInt(371, 132), cInt(372, 126), cInt(373, 132), cInt(374, 129), cInt(375, 129), cInt(376, 127),
	cInt(377, 126), cInt(379, 126), cInt(380, 126), cInt(381, 126), cInt(382, 127), cInt(383, 127), cInt(384, 127), cInt(385, 134), cInt(387, 126), cInt(388, 126), cInt(390, 132), cInt(392, 133), cInt(395, -2),/*CD2*/ cInt(420, 135), cInt(421, 135), cInt(423, 135),
	cInt(424, 135), cInt(426, 135), cInt(427, 135), cInt(429, 135), cInt(430, 135), cInt(433, 135), cInt(434, 135), cInt(436, 135), cInt(438, 135), cInt(440, 135), cInt(442, 135), cInt(445, 135), cInt(446, 135), cInt(450, 135), cInt(454, 136), cInt(455, 136),
	cInt(456, 137), cInt(457, 137), cInt(458, 137), cInt(459, 137), cInt(460, 137), cInt(461, 137), cInt(462, 137), cInt(463, 137), cInt(464, 137), cInt(465, 137), cInt(466, 137), cInt(467, 137), cInt(468, 137), cInt(469, 137), cInt(470, 137), cInt(471, 137),
	cInt(472, 137), cInt(473, 137), cInt(474, 137), cInt(475, 137), cInt(477, 137), cInt(478, 137), cInt(479, 137), cInt(480, 137), cInt(482, 137), cInt(483, 137), cInt(490, 65), cInt(494, 65), cInt(498, 65), cInt(502, 70), cInt(506, 70), cInt(510, 70),
	cInt(514, 69), cInt(518, 74), cInt(522, 74), cInt(525, 68), cInt(530, 68), cInt(531, 68), cInt(532, 68), cInt(533, 68), cInt(534, 68), cInt(536, 68), cInt(537, 68), cInt(538, 68), cInt(539, 68), cInt(540, 68), cInt(541, 68), cInt(542, 68),
	cInt(550, 68), cInt(552, 68), cInt(553, 68), cInt(554, 68), cInt(555, 74), cInt(556, 74), cInt(560, 74), cInt(563, 82), cInt(570, 74), cInt(571, 73), cInt(575, 70), cInt(600, 81), cInt(610, 81), cInt(612, 71), cInt(614, 70), cInt(615, 82),
	cInt(616, 82), cInt(618, 64), cInt(630, 183), cInt(632, 73), cInt(636, 70), cInt(637, 70), cInt(638, 74), cInt(639, 74), cInt(640, 82), cInt(641, 149), cInt(642, 149), cInt(643, 148), cInt(644, 149), cInt(645, 149), cInt(646, 146), cInt(647, 147),
	cInt(648, 147), cInt(650, 147), cInt(651, 147), cInt(655, 150), cInt(659, 77), cInt(670, 74), cInt(672, 74), cInt(690, 73), cInt(692, 149), cInt(693, 149), cInt(700, 149), cInt(710, 73), cInt(712, 80), cInt(720, 80), cInt(721, 146), cInt(722, 146),
	cInt(723, 151), cInt(740, 148), cInt(742, 183), cInt(743, 73), cInt(748, 74), cInt(750, 74), cInt(760, 84), cInt(765, 74), cInt(772, 183), cInt(774, 195), cInt(776, 183), cInt(778, 183), cInt(780, 183), cInt(782, 195), cInt(784, 183), cInt(786, 183),
	cInt(790, 195), cInt(800, 195), cInt(850, 74), cInt(852, 69), cInt(854, 77), cInt(856, 77), cInt(858, 74), cInt(860, 74), cInt(862, 77), cInt(864, 77), cInt(866, 77), cInt(868, 77), cInt(870, 77), cInt(872, 70), cInt(874, 65), cInt(876, 70),
	cInt(878, 70), cInt(880, 66), cInt(882, 66), cInt(884, 69), cInt(886, 74), cInt(888, 74), cInt(890, 69), cInt(892, 69), cInt(893, 124), cInt(894, 114), cInt(895, 120), cInt(900, 121), cInt(901, -3),/*CD3*/ cInt(910, 73), cInt(912, 71), cInt(1091, 185), cInt(1092, 185),
	cInt(1093, 186), cInt(1094, 186), cInt(1095, 186), cInt(1104, 186), cInt(1105, 74), cInt(1200, 71), cInt(1205, 204), cInt(1210, 204), cInt(1215, 204), cInt(1220, 204), cInt(1225, 204), cInt(1300, 204), cInt(1310, 183), cInt(1315, 71), cInt(1350, 71), cInt(1450, 207),
	cInt(1545, 74), cInt(1547, 71), cInt(1550, 69), cInt(1570, 82), cInt(1575, 82), cInt(1600, 155), cInt(1650, 156), cInt(1700, 157), cInt(1715, 157), cInt(1725, 157), cInt(1730, 157), cInt(1740, 158), cInt(1745, 158), cInt(1750, 158), cInt(1900, 169), cInt(2000, 164),
	cInt(2100, 170), cInt(2102, 170), cInt(2105, 171), cInt(2110, 172), cInt(2115, 172), cInt(2120, 172), cInt(2125, 172), cInt(2130, 170), cInt(2133, 171), cInt(2145, 170), cInt(2300, 168), cInt(2500, 160), cInt(2502, 173), cInt(2504, 222), cInt(2506, 223), cInt(2508, 220),
	cInt(2512, 220), cInt(2514, 223), cInt(2516, 223), cInt(2520, 223), cInt(2522, 223), cInt(2524, 223), cInt(2525, 223), cInt(2528, 223), cInt(2532, 223), cInt(2534, 219), cInt(2535, 223), cInt(2536, 223), cInt(2538, 224), cInt(2540, 224), cInt(2542, 224), cInt(2544, 222),
	cInt(2546, 223), cInt(2548, 226), cInt(2550, 219), cInt(2551, 219), cInt(2552, 219), cInt(2554, 221), cInt(2556, 221), cInt(2558, 221), cInt(2560, 221), cInt(2562, 226), cInt(2564, 221), cInt(3000, 213), cInt(3002, 213), cInt(3003, 213), cInt(3005, 213), cInt(3007, 210),
	cInt(3100, 208), cInt(3150, 180), cInt(3160, 209), cInt(3161, 209), cInt(3162, 209), cInt(3165, 209), cInt(3167, 208), cInt(3200, 173), cInt(3210, 173), cInt(3220, 173), cInt(3250, 173), cInt(3300, 173), cInt(3400, 208), cInt(3410, 208), cInt(3494, 188), cInt(3496, 188),
	cInt(3498, 188), cInt(3500, 188), cInt(3600, 183), cInt(3601, 166), cInt(3602, 166), cInt(3604, 166), cInt(3606, 166), cInt(3700, 209), cInt(3790, 209), cInt(3800, 208), cInt(3802, 181), cInt(3810, 181), cInt(3850, 181), cInt(3855, 181), cInt(3860, -4),/*CD4*/ cInt(4000, 249),
	cInt(4005, 228), cInt(4020, 248), cInt(4050, 229)
};

const int Data::drawPoints[256] =
{
	21, 4, 25, 27, 13, 12, 7, 21, 1, 41, 38, 50, 21, 6, 35, 24,
	30, 29, 33, 32, 21, 10, 8, 48, 27, 12, 2, 46, 9, 11, 5, 38,
	25, 44, 28, 23, 31, 29, 47, 22, 35, 30, 26, 25, 19, 9, 16, 23,
	4, 17, 18, 33, 45, 15, 37, 37, 24, 31, 43, 14, 41, 19, 39, 42,
	16, 23, 36, 23, 15, 14, 40, 39, 11, 44, 45, 9, 48, 32, 19, 6,
	3, 18, 14, 22, 24, 25, 28, 27, 34, 19, 49, 16, 35, 36, 23, 24,
	37, 26, 33, 34, 15, 23, 22, 50, 27, 36, 28, 37, 24, 15, 32, 14,
	16, 49, 19, 25, 34, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	21, 27, 7, 2, 8, 5, 4, 1, 21, 10, 22, 27, 50, 30, 35, 11,
	12, 24, 13, 29, 14, 9, 37, 3, 26, 6, 39, 15, 28, 36, 17, 23,
	18, 25, 31, 32, 17, 33, 42, 16, 19, 34, 39, 38, 17, 40, 41, 15,
	43, 44, 45, 46, 47, 48, 49, 48, 18, 17, 16, 14, 15, 32, 19, 34,
	24, 18, 17, 16, 14, 15, 32, 19, 34, 24, 18, 17, 16, 14, 15, 32,
	19, 34, 24, 19, 16, 14, 15, 32, 19, 34, 24, 16, 14, 34, 32, 19,
	34, 24, 16, 14, 15, 32, 19, 34, 24, 16, 34, 15, 32, 19, 34, 24,
	16, 14, 15, 32, 19, 4, 21, 28, 39, 16, 33, 33, 14, 15, 19, 50
};

const int Data::drawPointsLoc[256] =
{
	// field
	65, 78, 68, 64, 67, 81, 85, 87, 92, 93, 99, 101, 101/* and 182*/, 109, 113, 117,
	122, 125, 121, 124, 110, 110, 129, 134, 134, 134, -1, 135, 135, 136, 137, 137,
	137, 138, 138, 140, 138, 145, 145, 145, 154, 147, 146, 150, 149, 157, 157, 159,
	159, 160, 159, 167, -1, 167, 173, -1, 177, 177, 178, 182, 182, 182, 182, 181,
	181, 181, -1, 185, -1, -1, 182, 182, 189, 189, 189, 190, 191, 193, 197, 199,
	201, -1, 207, 210, 210, 211, 217, 217, 218, 218, 221, 225, -1, -1, -1, -1,
	-1, -1, -1, 228, 248, 237, 233, -1, -1, 243, 244, 245, 246, -1, 232, 236,
	231, 238, 240, 241, 245, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	// worldmap
	1, 1, 6, 8, 17, 15, 10, -1, 11, 14, 11, 20, 21, 15, 23, 15,
	15, 24, 62, 61, 57, 55, 53, 50, 26, 26, 30, 32, 32, 32, 37, 46,
	39, 39, 25, 13, 12, -1, 17, 41, 41, 41, 42, 41, 26, 26, 26, 32,
	31, 12, 11, 15, 21, 22, 15, 16, 51, 51, 51, 51, 51, 51, 51, 51,
	51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
	51, 51, 51, 51, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
	19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
	19, 19, 19, 19, 19, 1, 1, 15, 20, 43, 43, 43, 43, 47, 48, -1
};