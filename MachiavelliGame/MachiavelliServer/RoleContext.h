#pragma once

namespace std {

	class RoleContext
	{
	public:
		static RoleContext getInstance();
		virtual ~RoleContext();

	private:
		RoleContext();
	};
}//namespace std

