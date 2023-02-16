// Auto-generated. Do not edit!

// (in-package air_lab1.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class ControllerEvaluationStat {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.samples = null;
      this.last_error = null;
      this.average_error = null;
    }
    else {
      if (initObj.hasOwnProperty('samples')) {
        this.samples = initObj.samples
      }
      else {
        this.samples = 0;
      }
      if (initObj.hasOwnProperty('last_error')) {
        this.last_error = initObj.last_error
      }
      else {
        this.last_error = 0.0;
      }
      if (initObj.hasOwnProperty('average_error')) {
        this.average_error = initObj.average_error
      }
      else {
        this.average_error = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ControllerEvaluationStat
    // Serialize message field [samples]
    bufferOffset = _serializer.int32(obj.samples, buffer, bufferOffset);
    // Serialize message field [last_error]
    bufferOffset = _serializer.float64(obj.last_error, buffer, bufferOffset);
    // Serialize message field [average_error]
    bufferOffset = _serializer.float64(obj.average_error, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ControllerEvaluationStat
    let len;
    let data = new ControllerEvaluationStat(null);
    // Deserialize message field [samples]
    data.samples = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [last_error]
    data.last_error = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [average_error]
    data.average_error = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 20;
  }

  static datatype() {
    // Returns string type for a message object
    return 'air_lab1/ControllerEvaluationStat';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '46c88f67df59b89f4eac2f8df597d291';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 samples           # Number of samples used for computing the error
    float64 last_error      # Last error
    float64 average_error   # Average error
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new ControllerEvaluationStat(null);
    if (msg.samples !== undefined) {
      resolved.samples = msg.samples;
    }
    else {
      resolved.samples = 0
    }

    if (msg.last_error !== undefined) {
      resolved.last_error = msg.last_error;
    }
    else {
      resolved.last_error = 0.0
    }

    if (msg.average_error !== undefined) {
      resolved.average_error = msg.average_error;
    }
    else {
      resolved.average_error = 0.0
    }

    return resolved;
    }
};

module.exports = ControllerEvaluationStat;
