#include "typy.h"
#include "ObiektMiotajcy.h"


typ4::typ4(const ObiektMiotajacy* obj): _pointer(obj) { }
typ4::~typ4(){ delete _pointer; }