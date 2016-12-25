
Vector::Vector(real x, real y, real z, real w):
x(x), y(y), z(z), w(w){}

Vector::Vector(std::initializer_list<real> v){
    auto itr = v.begin();
    x = *(itr++);
    y = *(itr++);
    z = *itr;
    w = 0;
}

real Vector::squreLength() const {
    return x * x + y * y + z * z;
}

real Vector::length() const{
    return real_sqrt(x * x + y * y + z * z);
}

real  Vector::operator()() const{
    return length();
}

Vector& Vector::operator+=(const Vector& v){
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector Vector::operator+(const Vector& v) const{
    return Vector(x + v.x, y + v.y, z + v.z);
}

Vector& Vector::operator-=(const Vector& v){
    x -= v.x;
    y -= v.y;
    z -= v.z;
    
    return *this;
}


Vector Vector::operator-(const Vector& v) const{
    return Vector(x - v.x, y - v.y, z - v.z);
}

Vector Vector::compProduct(const Vector& v) const {
    return Vector(x * v.x, y * v.y, z * v.z);
}

Vector& Vector::operator*=(real s){
    x *= s;
    y *= s;
    z *= s;
    return *this;
}

Vector Vector::operator*(const real s) const{
    return Vector(x * s, y * s, z * s);
}

Vector& Vector::addScaled(const Vector& v, real s){
    x += v.x * s;
    y += v.y * s;
    z += v.z * s;
    return *this;
}

bool Vector::operator==(const Vector& v) const{
    if (this == &v) {
        return true;
    }
    
    return real_equals(x, v.x) && real_equals(y, v.y) && real_equals(z, v.z);
}

bool Vector::operator<=(const Vector& v) const{
    if(this == &v){
        return true;
    }
    
    return x <= v.x && y <= v.y && z <= v.z;
}

Vector& Vector::normalize(){
    real mag = length();
    
    *this *= 1/mag;
    
    return *this;
}

real Vector::operator[](const char key) const{
    switch(key){
        case 'x': return x;
        case 'y': return y;
        case 'z': return z;
        default: throw "Illegal argument";
    }
}

real& Vector::operator[](const char key){
    switch (key) {
        case 'x': return x;
        case 'y': return y;
        case 'z': return z;
        case 'w' : return w;
        default: throw "Illegal argument";
    }
}

real Vector::operator[](const unsigned i) const {
    return data[i];
}

real& Vector::operator[](const unsigned i) {
    return data[i];
}


real Vector::dot(const Vector& v) const{
    return x * v.x + y * v.y + z * v.z;
}

Vector Vector::cross(const Vector& v) const{
    return Vector{
        y * v.z - z * v.y,
        z * v.x - x * v.z,
        x * v.y - y * v.x
    };
}

Vector& Vector::crossProductUpdate(const Vector& v){
    *this = cross(v);
    
    return *this;
}

real Vector::operator%(const Vector& v) const{
    return dot(v);
}

Vector Vector::operator*(const Vector& v) const{
    return cross(v);
}

Vector& Vector::operator*=(const Vector& v){
    return crossProductUpdate(v);
}

Vector& Vector::invert(){
    x *= -1;
    y *= -1;
    z *= -1;
    return *this;
}

Vector& Vector::operator-(){
    invert();
    return *this;
}

Vector::operator real*(){
    return data;
}

Vector& Vector::clear(){
    x = 0;
    y = 0;
    z = 0;
    w = 0;
    return *this;
}

real Vector::angleBetween(Vector a, Vector b){
    a.normalize();
    b.normalize();
    real dot = a.dot(b);
    return real_acos(dot)/DEG_TO_RAD;
    
}

 std::ostream& operator<<(std::ostream& out, const Vector& v){
    out << "v(" << v.x << ", " << v.y << ", " << v.z;
    if(!(fabs(v.w - 0) < epsilon)) out << "," << v.w;
    out << ")";
    return out;
}

