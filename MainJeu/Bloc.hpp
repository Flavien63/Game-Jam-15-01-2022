#pragma once
class Bloc
{
	public:
		Bloc();
		virtual ~Bloc() = 0;
		virtual void rendreActif() = 0;
		virtual bool estActif() = 0;
};

