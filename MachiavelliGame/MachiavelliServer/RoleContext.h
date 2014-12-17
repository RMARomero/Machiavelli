#pragma once

	class RoleContext
	{
	public:
		static RoleContext& getInstance();
		virtual ~RoleContext();

	private:
		RoleContext() {}
	};

