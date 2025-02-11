// Tron


#include "GameMode/TronRpgGameMode.h"

#include "Character/Player/TronRpgPlayerCharacter.h"
#include "Controller/TronRpgPlayerController.h"

ATronRpgGameMode::ATronRpgGameMode()
{
	DefaultPawnClass = ATronRpgPlayerCharacter::StaticClass();
	PlayerControllerClass = ATronRpgPlayerController::StaticClass();
}
