// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby granted.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CombatHandler.generated.h"

class UCombat;

/**
 * 
 */
UCLASS()
class COMBATSYSTEM_API UCombatHandler : public UObject
{
	GENERATED_BODY()

public:

	void Initialize(UCombat* owner);

private:

	UCombat* combat;
	
};
