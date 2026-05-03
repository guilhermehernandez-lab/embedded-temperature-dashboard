from flask import Flask, request, jsonify, send_from_directory 

app = Flask(__name__) 

data_store = [] 



@app.route("/temperature", methods=["POST"])
def receive_temperature():
    data = request.json
    print("Received temperature:", data)
    data_store.append(data)
    return jsonify({"status": "ok"})


@app.route("/data", methods=["GET"])
def get_data():
    return jsonify(data_store)


@app.route("/") 
def index():
    return send_from_directory(".", "index.html")


if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)
