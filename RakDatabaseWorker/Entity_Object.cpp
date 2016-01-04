#include "Entity_Object.h"


Entity_Object::Entity_Object()
{
}


Entity_Object::~Entity_Object()
{
}

void Entity_Object::loadData(RakNet::BitStream* to){
	try{
		LOG(INFO) << "Loading all entity's data";
		typedef odb::query<Entity> queryS;
		typedef odb::result<Entity> resultS;
		odb::transaction t(dataBase->begin());

		resultS r(dataBase->query<Entity>(queryS::id == _id));


		for (resultS::iterator i(r.begin()); i != r.end(); ++i)
		{
			//char str[100];
			//itoa((*i).id(), str, 10);
			//LOG(INFO) << "ID: " << str;
			//itoa((*i).upcastId(), str, 10);
			//LOG(INFO) << "Uid: " << str;
			//itoa((*i).worldId(), str, 10);
			//LOG(INFO) << "World Id: " << str;
			to->Write((*i).id());
			to->Write((*i).worldId());
			to->Write((*i).bodyId());
			to->Write((*i).x());
			to->Write((*i).y());
			to->Write((*i).z());
			to->Write((*i).x_grid());
			to->Write((*i).y_grid());
		}
		t.commit();

		LOG(INFO) << "Loading physics entity's data";

		typedef odb::query<PhysicsData> query;
		typedef odb::result<PhysicsData> result;
		odb::transaction tr(dataBase->begin());

		result r2(dataBase->query<PhysicsData>(query::id == _id));
		bool has_data = false;
		for (result::iterator i(r2.begin()); i != r2.end(); ++i){
			has_data = true;
			to->Write(has_data);
			to->Write((*i).shape_id());
			to->Write((*i).height());
			to->Write((*i).radius());
			to->Write((*i).has_mass());

			if ((*i).has_mass())
				to->Write((*i).mass());

		}
		tr.commit();
		if (!has_data){
			to->Write(has_data);
		}
	}
	catch (const odb::exception& e)
	{
		cerr << e.what() << endl;
	}
};

void Entity_Object::set_id(int i)
{
	_id = i;
}