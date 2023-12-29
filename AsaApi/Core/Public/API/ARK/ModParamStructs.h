#pragma once

/*Enums*/

enum class DrawSphereType : unsigned char
{
	Wireframe,
	TekShield
};

enum class Position : unsigned char
{
	Left,
	Center,
	Right
};

struct DrawDebugLine_Params
{
	/*IN params*/
	FVector Start;
	FVector End;
	FLinearColor Color;
	int Duration;
};


struct DrawDebugSphere_Params
{
	/*IN params*/
	FVector Center;
	double Radius;
	int ForPlayerID;
	int ForTribeID;
	FLinearColor Color;
	int Duration;
	DrawSphereType DrawType;
	/*OUT params (return)*/
	AActor* SphereActor;
};

struct AsaApiUtilsNotification
{
	FString NotificationId; /*leave blank always*/
	FString Text;
	TArray<FString> RecipientEOS;
	FLinearColor BackgroundColor;
	FLinearColor TextColor;
	double DisplayScale;
	double DisplayTime;
	Position TextJustification;
	Position NotificationScreenPosition;
	bool bAddToChat;
};

struct AddNotification_Params
{
	/*IN params*/
	AsaApiUtilsNotification Notification;
	/*OUT params (return)*/
	FString NotificationId;
};

struct APrimalBuff_ApiUtils : APrimalBuff
{
	// Fields

	TArray<AsaApiUtilsNotification>& NotificationsField()
	{
		FProperty* NotificationsProperty = FindProperty("Notifications");
		return *NotificationsProperty->Get<TArray<AsaApiUtilsNotification>*>(this);
	}

	// Functions

	AsaApiUtilsNotification& GetNotificationForId(const FString& id)
	{
		auto& Notifications = NotificationsField();
		for (auto& Notification : Notifications)
		{
			if (Notification.NotificationId.Equals(id))
			{
				return Notification;
			}
		}

		static AsaApiUtilsNotification EmptyNotification;
		return EmptyNotification;
	}
};