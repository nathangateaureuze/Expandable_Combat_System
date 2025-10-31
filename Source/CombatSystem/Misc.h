// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

namespace Misc
{
	template <typename T>
	static TArray<T> BubbleSortInvert(TArray<T> objects, TArray<float> values)
	{
		if (objects.Num() != values.Num())
		{
			UE_LOG(LogTemp, Error, TEXT("BubbleSort - objects and values are not corresponding"));
			return objects;
		}

		bool swapped = true;

		while (swapped)
		{
			swapped = false;

			for (int i = 1; i < values.Num(); i++)
			{
				if (values[i] > values[i - 1])
				{
					values.Swap(i, i - 1);
					objects.Swap(i, i - 1);

					swapped = true;
				}
			}

		}

		return objects;
	}
}