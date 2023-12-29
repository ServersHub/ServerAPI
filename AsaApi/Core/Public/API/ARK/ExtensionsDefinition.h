#pragma once

// Actor extensions

FORCEINLINE FVector ActorExtensions::GetActorForwardVector()
{
    AActor* _this = reinterpret_cast<AActor*>(this);
    USceneComponent* RootComponent = _this->RootComponentField().Get();
    if (RootComponent)
    {
        return RootComponent->ComponentToWorldField().GetUnitAxis(EAxis::X);
    }

    return FVector::ZeroVector;
}

FORCEINLINE bool ActorExtensions::IsA(UClass* SomeBase)
{
    return reinterpret_cast<AActor*>(this)->ClassPrivateField()->IsChildOf(SomeBase);
}

FORCEINLINE FVector ActorExtensions::GetLocation()
{
    AActor* _this = reinterpret_cast<AActor*>(this);
    auto* root = _this->RootComponentField().Get();
    if (root)
    {
        UE::Math::TTransform<double> transform = root->ComponentToWorldField();
        return transform.GetLocation();
    }
    return FVector();
}

// Player Controller Extensions

FORCEINLINE FString PlayerControllerExtensions::GetEOSId()
{
    APlayerController* _this = reinterpret_cast<APlayerController*>(this);
	return AsaApi::IApiUtils::GetEOSIDFromController(_this);
}