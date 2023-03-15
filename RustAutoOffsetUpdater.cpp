#include <iostream>
#include "json.hpp"
#include <urlmon.h>
#include <fstream>
#pragma comment(lib, "urlmon.lib")
#include "Offsets.hpp"

using json = nlohmann::json;

using namespace std;


#define log(msg) std::cout << (msg) << std::endl
#define logbool(msg,bl) std::cout << (msg) << bl << std::endl


void UpdateScriptOffsets() {
	string dwnld_URL2 = ("https://raw.githubusercontent.com/Akandesh/BlazeDumper-Rust/master/script.json");
	string savepath2 = ("script.json");
	URLDownloadToFile(NULL, dwnld_URL2.c_str(), savepath2.c_str(), 0, NULL);

	std::ifstream dosya2("script.json");

	json data = json::parse(dosya2);

	for (auto& obj : data["ScriptMetadata"]) {
		if (obj["Signature"] == "System_Collections_Generic_List_BaseGameMode__c*") {
			int address = obj["Address"];
			oBaseGameMode = address;
			logbool("MainBaseGameMode:", address);
		}
		else if (obj["Signature"] == "BaseGameMode_c*") {
			int address = obj["Address"];
			oBaseGameModeHardCore = address;
			logbool("BaseGameModeHardCore:", address);
		}
		else if (obj["Signature"] == "ConVar_Graphics_c*") {
			int address = obj["Address"];
			oConvarGraphics = address;
			logbool("ConvarGraphics:", address);
		}
		else if (obj["Signature"] == "ConVar_Client_c*") {
			int address = obj["Address"];
			oConvarClient = address;
			logbool("ConvarClient:", address);
		}
		else if (obj["Signature"] == "ConsoleSystem_Index_c*") {
			int address = obj["Address"];
			oConsoleSystem = address;
			logbool("ConsoleSystem:", address);
		}
		else if (obj["Signature"] == "ConVar_Admin_c*") {
			int address = obj["Address"];
			oConvarAdmin = address;
			logbool("ConvarAdmin:", address);
		}
		else if (obj["Signature"] == "OcclusionCulling_c*") {
			int address = obj["Address"];
			oOcclusionCulling = address;
			logbool("OcclusionCulling:", address);
		}
		else if (obj["Signature"] == "ConVar_Culling_c*") {
			int address = obj["Address"];
			oConVarCulling = address;
			logbool("ConVarCulling:", address);
		}
	}
	std::remove(("script.json"));
}

void UpdateDumpOffsets() {
	string dwnld_URL = ("https://raw.githubusercontent.com/Akandesh/BlazeDumper-Rust/master/dump.cs");
	string savepath = ("dump.cs");
	URLDownloadToFile(NULL, dwnld_URL.c_str(), savepath.c_str(), 0, NULL);

	std::ifstream dosya(("dump.cs"));
	std::string line;
	std::string file_content;
	while (std::getline(dosya, line)) {
		file_content += line + ("\n");
	}
	for (const auto& offset_info : offsets) {
		std::string class_start_str = offset_info.class_name;
		std::string class_end_str = ("}");
		std::size_t class_start_pos = file_content.find(class_start_str);
		std::size_t class_end_pos = file_content.find(class_end_str, class_start_pos);
		std::string class_content = file_content.substr(class_start_pos, class_end_pos - class_start_pos + 1);
		std::size_t offset_pos = class_content.find(offset_info.offset_name);
		if (offset_pos != std::string::npos) {
			std::string search_str = ("0x");
			std::size_t hex_pos = class_content.find(search_str, offset_pos);
			if (hex_pos != std::string::npos) {
				std::string hex_str = class_content.substr(hex_pos);
				hex_str = hex_str.substr(0, hex_str.find_first_of((" \n\r\t/")));
				uintptr_t result = std::stoull(hex_str, nullptr, 16);

				if (offset_info.offset_name == ("public BasePlayer.PlayerFlags playerFlags;")) {
					oPlayerFlag = result;
				}
				else if (offset_info.offset_name == ("public BaseMovement movement;")) {
					oPlayerMovement = result;
				}
				else if (offset_info.offset_name == ("private uint clActiveItem;")) {
					oActiveUID = result;
				}
				else if (offset_info.offset_name == ("public PlayerInventory inventory;")) {
					oPlayerInventory = result;
				}
				else if (offset_info.offset_name == ("public ItemContainer containerBelt;")) {
					oContainerBelt = result;
				}
				else if (offset_info.offset_name == ("public List<Item> contents;")) {
					oBeltContentList = result;
				}
				else if (offset_info.offset_name == ("private EntityRef heldEntity")) {
					oHeld = result;
				}
				else if (offset_info.offset_name == ("public RecoilProperties recoil;")) {
					oRecoilProperties = result;
				}
				else if (offset_info.offset_name == ("public float recoilYawMin;")) {
					oRecoilYawMin = result;
				}
				else if (offset_info.offset_name == ("public float recoilYawMax;")) {
					oRecoilYawMax = result;
				}
				else if (offset_info.offset_name == ("public float recoilPitchMin;")) {
					oRecoilPitchMin = result;
				}
				else if (offset_info.offset_name == ("public float recoilPitchMax;")) {
					oRecoilPitchMax = result;
				}
				else if (offset_info.offset_name == ("public float aimconeCurveScale;")) {
					oAimconeCurveScale = result;
				}
				else if (offset_info.offset_name == ("private float stancePenalty;")) {
					oStancePenalty = result;
				}
				else if (offset_info.offset_name == ("public float aimCone;")) {
					oAimCone = result;
				}
				else if (offset_info.offset_name == ("public float hipAimCone;")) {
					oHipAimCone = result;
				}
				else if (offset_info.offset_name == ("public float aimconePenaltyPerShot;")) {
					oAimconePenaltyPerShot = result;
				}
				else if (offset_info.offset_name == ("public bool automatic;")) {
					oAutomatic = result;
				}
				else if (offset_info.offset_name == ("public float capsuleHeight;")) {
					oCapsuleHeight = result;
				}
				else if (offset_info.offset_name == ("public float capsuleCenter;")) {
					oCapsuleCenter = result;
				}
				else if (offset_info.offset_name == ("private float groundAngle;")) {
					oGroundAngle = result;
				}
				else if (offset_info.offset_name == ("private float groundAngleNew;")) {
					oGroundAngleNew = result;
				}
				else if (offset_info.offset_name == ("public float gravityMultiplier;")) {
					oGravityMultiplier = result;
				}
				std::cout << offset_info.offset_name << (" ") << hex_str << std::endl;
			}
		}
	}
	dosya.close();

	std::remove(("dump.cs"));
}

int main()
{
	UpdateScriptOffsets();
	UpdateDumpOffsets();
	while (true)
	{

	}
}
